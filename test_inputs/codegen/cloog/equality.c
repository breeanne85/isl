for (int c0 = 0, c0_end = 5; c0 <= c0_end; c0 += 1)
  for (int c1 = c0 <= 2 ? 2 * c0 : 4, c1_end = c0 >= 2 ? 2 * c0 : 4; c1 <= c1_end; c1 += 1) {
    if (c1 == 2 * c0)
      S1(c0, 2 * c0);
    if (c1 == 4)
      S2(c0, 4);
  }
