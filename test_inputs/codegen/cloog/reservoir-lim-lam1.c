for (int c0 = -99, c0_end = 100; c0 <= c0_end; c0 += 1) {
  if (c0 >= 1)
    S2(c0, 1);
  for (int c1 = max(1, -c0 + 1), c1_end = min(99, -c0 + 100); c1 <= c1_end; c1 += 1) {
    S1(c0 + c1, c1);
    S2(c0 + c1, c1 + 1);
  }
  if (c0 <= 0)
    S1(c0 + 100, 100);
}
