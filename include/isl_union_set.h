#ifndef ISL_UNION_SET_H
#define ISL_UNION_SET_H

#include <isl_point.h>
#include <isl_union_map.h>

#if defined(__cplusplus)
extern "C" {
#endif

__isl_give isl_union_set *isl_union_set_from_set(__isl_take isl_set *set);
__isl_give isl_union_set *isl_union_set_empty(__isl_take isl_dim *dim);
__isl_give isl_union_set *isl_union_set_copy(__isl_keep isl_union_set *uset);
void isl_union_set_free(__isl_take isl_union_set *uset);

__isl_give isl_dim *isl_union_set_get_dim(__isl_keep isl_union_set *uset);

__isl_give isl_union_set *isl_union_set_affine_hull(
	__isl_take isl_union_set *uset);
__isl_give isl_union_set *isl_union_set_coalesce(
	__isl_take isl_union_set *uset);
__isl_give isl_union_set *isl_union_set_compute_divs(
	__isl_take isl_union_set *uset);
__isl_give isl_union_set *isl_union_set_lexmin(__isl_take isl_union_set *uset);
__isl_give isl_union_set *isl_union_set_lexmax(__isl_take isl_union_set *uset);

__isl_give isl_union_set *isl_union_set_add_set(__isl_take isl_union_set *uset,
	__isl_take isl_set *set);
__isl_give isl_union_set *isl_union_set_union(__isl_take isl_union_set *uset1,
	__isl_take isl_union_set *uset2);
__isl_give isl_union_set *isl_union_set_subtract(
	__isl_take isl_union_set *uset1, __isl_take isl_union_set *uset2);
__isl_give isl_union_set *isl_union_set_intersect(
	__isl_take isl_union_set *uset1, __isl_take isl_union_set *uset2);
__isl_give isl_union_set *isl_union_set_product(__isl_take isl_union_set *uset1,
	__isl_take isl_union_set *uset2);
__isl_give isl_union_set *isl_union_set_gist(__isl_take isl_union_set *uset,
	__isl_take isl_union_set *context);

__isl_give isl_union_set *isl_union_set_apply(
	__isl_take isl_union_set *uset, __isl_take isl_union_map *umap);

int isl_union_set_is_empty(__isl_keep isl_union_set *uset);

int isl_union_set_foreach_set(__isl_keep isl_union_set *uset,
	int (*fn)(__isl_take isl_set *set, void *user), void *user);
int isl_union_set_foreach_point(__isl_keep isl_union_set *uset,
	int (*fn)(__isl_take isl_point *pnt, void *user), void *user);

__isl_give isl_basic_set *isl_union_set_sample(__isl_take isl_union_set *uset);

__isl_give isl_printer *isl_printer_print_union_set(__isl_take isl_printer *p,
	__isl_keep isl_union_set *uset);

#if defined(__cplusplus)
}
#endif

#endif
