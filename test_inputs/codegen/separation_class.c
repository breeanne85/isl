{
  for (int c0 = 0, c0_end = 8; c0 <= c0_end; c0 += 1) {
    for (int c1 = 0, c1_end = -c0 + 8; c1 <= c1_end; c1 += 1)
      for (int c2 = 10 * c0, c2_end = 10 * c0 + 9; c2 <= c2_end; c2 += 1)
        for (int c3 = 10 * c1, c3_end = 10 * c1 + 9; c3 <= c3_end; c3 += 1)
          A(c2, c3);
    for (int c1 = -c0 + 9, c1_end = -c0 + 10; c1 <= c1_end; c1 += 1)
      for (int c2 = 10 * c0, c2_end = min(10 * c0 + 9, -10 * c1 + 100); c2 <= c2_end; c2 += 1)
        for (int c3 = 10 * c1, c3_end = min(10 * c1 + 9, -c2 + 100); c3 <= c3_end; c3 += 1)
          A(c2, c3);
  }
  for (int c0 = 9, c0_end = 10; c0 <= c0_end; c0 += 1)
    for (int c1 = 0, c1_end = -c0 + 10; c1 <= c1_end; c1 += 1)
      for (int c2 = 10 * c0, c2_end = min(10 * c0 + 9, -10 * c1 + 100); c2 <= c2_end; c2 += 1)
        for (int c3 = 10 * c1, c3_end = min(10 * c1 + 9, -c2 + 100); c3 <= c3_end; c3 += 1)
          A(c2, c3);
}
