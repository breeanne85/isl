for (int c0 = 0, c0_end = 14; c0 <= c0_end; c0 += 1)
  for (int c1 = max(2 * c0 - 12, -c0 + 3 * ((c0 + 1) / 2)), c1_end = min(2 * c0, c0 / 2 + 9); c1 <= c1_end; c1 += 3)
    s0((2 * c0 - c1) / 3, (-c0 + 2 * c1) / 3);
