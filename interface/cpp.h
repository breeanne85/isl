#include "generator.h"

using namespace std;
using namespace clang;

class cpp_generator : public generator {
public:
	cpp_generator(set<RecordDecl *> &exported_types,
		set<FunctionDecl *> exported_functions,
		set<FunctionDecl *> functions);

	virtual void generate() override;
private:

	/* Print forward declarations for all classes to "os".
	 */
	void print_forward_declarations(ostream &os);

	/* Print all declarations to "os".
	 */
	void print_declarations(ostream &os);

	/* Print declarations for class "clazz" to "os".
	 */
	void print_class(ostream &os, const isl_class &clazz);

	/* Print forward declaration of class "clazz" to "os".
	 */
	void print_class_forward_decl(ostream &os, const isl_class &clazz);

	/* Print global constructor method to "os".
	 *
	 * Each class has one global constructor:
	 *
	 * 	Set manage(__isl_take isl_set *Ptr);
	 *
	 * The only public way to construct isl C++ objects from a raw pointer
	 * is through this global constructor method. This ensures isl object
	 * constructions is very explicit and pointers do not converted by
	 * accident. Due to overloading, manage() can be called on any isl
	 * raw pointer and the corresponding object is automatically
	 * constructed, without the user having to choose the right isl object
	 * type.
	 *
	 */
	void print_class_global_constructor(ostream &os,
		const isl_class &clazz);

	/* Print declarations of private constructors for class "clazz" to "os".
	 *
	 * Each class currently as one private constructor:
	 *
	 * 	1) Constructor from a plain isl_* C pointer
	 *
	 * Example:
	 *
	 * 	Set(__isl_take isl_set *Ptr);
	 *
	 * The raw pointer constructor is kept private. Object construction
	 * is only possible through isl::manage().
	 */
	void print_private_constructors(ostream &os, const isl_class &clazz);

	/* Print declarations of copy assignment operator for class "clazz"
	 * to "os".
	 *
	 * Each class has one assignment operator.
	 *
	 * 	Set& Set::operator=(Set Obj)
	 *
	 */
	void print_copy_assignment(ostream &os, const isl_class &clazz);

	/* Print declarations of public constructors for class "clazz" to "os".
	 *
	 * Each class currently as two public constructors:
	 *
	 * 	1) A default constructor
	 * 	2) A copy constructor
	 *
	 * Example:
	 *
	 *	Set();
	 *	Set(const Set &set);
	 */
	void print_public_constructors(ostream &os, const isl_class &clazz);

	/* Print declarations for conversion constructors for class "class"
	 * to "os".
	 *
	 * Add for each isl function that is marked as __isl_constructor and
	 * has a single isl_type argument a conversion constructor.
	 *
	 * Example:
	 *
	 * 	inline UnionSet(BasicSet *Obj);
	 *      inline UnionSet(Set *Obj);
	 *
	 */
	void print_conversion_constructors(ostream &os, const isl_class &clazz);

	/* Print declaration of destructor for class "clazz" to "os".
	 */
	void print_destructor(ostream &os, const isl_class &clazz);

	/* Print declaration of pointer functions for class "clazz" to "os".
	 *
	 * To obtain a raw pointer three functions are provided:
	 *
	 * 	1) __isl_give isl_set *copy()
	 *
	 * 	  Returns a pointer to a _copy_ of the internal object
	 *
	 * 	2) __isl_keep isl_set *get()
	 *
	 * 	  Returns a pointer to the internal object
	 *
	 * 	3) __isl_give isl_set *release()
	 *
	 * 	  Returns a pointer to the internal object and resets the
	 * 	  internal pointer to nullptr.
	 *
	 * 	4) bool isNull()
	 *
	 * 	  Check if the current object is a null pointer.
	 *
	 * The functions get() and release() model std::unique ptr. The copy()
	 * function is an extension to allow the user to explicitly copy
	 * the underlying object.
	 *
	 * Also generate a declaration to delete copy() for r-values. For
	 * r-values release() should be used to avoid unnecessary copies.
	 */
	void print_ptr(ostream &os, const isl_class &clazz);

	/* Print implementation of getStr() method for class "clazz" to "os",
	 * if isl_*_to_str is available.
	 */
	void print_str(ostream &os, const isl_class &clazz);

	/* Print declaration of getCtx() method for class "clazz", if
	 * isl_type_get_ctx() is available.
	 */
	void print_get_ctx(ostream &os, const isl_class &clazz);

	/* Print declarations for class "clazz".
	 */
	void print_methods(ostream &os, const isl_class &clazz);

	/* Print declarations for methods of name "fullname" in class "clazz".
	 */
	void print_method(ostream &os, const isl_class &clazz,
		const string &fullname, const set<FunctionDecl *> &methods);

	/* Print declarations for "method" in class "clazz".
	 */
	void print_method(ostream &os,
		const isl_class &clazz, FunctionDecl *method);

	/* Print all implementations to "os".
	 */
	void print_implementations(ostream &os);

	/* Print implementations for class "clazz" to "os".
	 */
	void print_class_impl(ostream &os, const isl_class &clazz);

	/* Print implementation of global constructor method to "os".
	 */
	void print_class_global_constructor_impl(ostream &os,
		const isl_class &clazz);

	/* Print implementations of private constructors for class "clazz" to
	 * "os".
	 */
	void print_private_constructors_impl(ostream &os,
		const isl_class &clazz);

	/* Print implementations of public constructors for class "clazz" to
	 * "os".
	 */
	void print_public_constructors_impl(ostream &os,
		const isl_class &clazz);

	/* Print implementations of conversion constructors for class "clazz"
	 * to "os".
	 */
	void print_conversion_constructors_impl(ostream &os,
		const isl_class &clazz);

	/* Print implementation of copy assignment operator for class "clazz"
	 * to "os".
	 */
	void print_copy_assignment_impl(ostream &os, const isl_class &clazz);

	/* Print implementation of destructor for class "clazz" to "os".
	 */
	void print_destructor_impl(ostream &os, const isl_class &clazz);

	/* Print implementation of ptr() function for class "clazz" to "os".
	 */
	void print_ptr_impl(ostream &os, const isl_class &clazz);

	/* Print implementation of getStr() method for class "clazz" to "os",
	 * if isl_*_to_str is available.
	 */
	void print_str_impl(ostream &os, const isl_class &clazz);

	/* Print implementation of getCtx() method for class "clazz" to "os",
	 * if isl_type_get_ctx() is available.
	 */
	void print_get_ctx_impl(ostream &os, const isl_class &clazz);

	/* Print definitions for class "clazz".
	 */
	void print_methods_impl(ostream &os, const isl_class &clazz);

	/* Print definitions for methods of name "fullname" in class "clazz".
	 */
	void print_method_impl(ostream &os, const isl_class &clazz,
		const string &fullname, const set<FunctionDecl *> &methods);

	/* Print definition for "method" in class "clazz".
	 */
	void print_method_impl(ostream &os, const isl_class &clazz,
		FunctionDecl *method);

	/* Print the header for "method" in class "clazz".
	 *
	 * Print the header as declaration if "is_declaration" is set,
	 * otherwise print the header of a method definition.
	 */
	void print_method_header(ostream &os, const isl_class &clazz,
		FunctionDecl *method, bool is_declaration);

	/* Verify if the C++ generator can generate this type of method.
	 */
	bool is_supported_method(const isl_class &clazz, FunctionDecl *method);

	/* Verify if the C++ generator supports parameter "param".
	 */
	bool is_supported_method_param(ParmVarDecl *param);

	/* Verify if the C++ generator supports returntype "rettype".
	 */
	bool is_supported_method_rettype(QualType type);

	/* Translate the isl type name into its corresponding C++ type.
	 *
	 * To obtain the C++ type name, the 'isl_' prefix is removed and the
	 * remainder * is translated to CamelCase.
	 *
	 * isl_basic_set -> BasicSet
	 *
	 */
	string type2cpp(string name);

	/* Convert a string "input" to CamelCase.
	 *
	 * If "start_lowercase" is set, the first letter remains lowercase.
	 */
	string to_camel_case(const string &input, bool start_lowercase = false);

	/* Check if "cons" is a conversion constructor.
	 */
	bool is_conversion_constructor(FunctionDecl *cons);
};
