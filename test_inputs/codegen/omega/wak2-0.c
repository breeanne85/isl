{
  for (int c0 = a1, c0_end = min(b1, a2 - 1); c0 <= c0_end; c0 += 1)
    for (int c1_0 = c1, c1_0_end = d1; c1_0 <= c1_0_end; c1_0 += 1)
      s0(c0, c1_0);
  if (c2 >= d2 + 1) {
    for (int c0 = max(a1, a2), c0_end = min(b1, b2); c0 <= c0_end; c0 += 1)
      for (int c1_0 = c1, c1_0_end = d1; c1_0 <= c1_0_end; c1_0 += 1)
        s0(c0, c1_0);
  } else
    for (int c0 = a2, c0_end = b2; c0 <= c0_end; c0 += 1) {
      if (c0 >= a1 && b1 >= c0)
        for (int c1_0 = c1, c1_0_end = min(d1, c2 - 1); c1_0 <= c1_0_end; c1_0 += 1)
          s0(c0, c1_0);
      for (int c1_0 = c2, c1_0_end = d2; c1_0 <= c1_0_end; c1_0 += 1) {
        if (c0 >= a1 && b1 >= c0 && c1_0 >= c1 && d1 >= c1_0)
          s0(c0, c1_0);
        s1(c0, c1_0);
      }
      if (c0 >= a1 && b1 >= c0)
        for (int c1_0 = max(c1, d2 + 1), c1_0_end = d1; c1_0 <= c1_0_end; c1_0 += 1)
          s0(c0, c1_0);
    }
  for (int c0 = max(max(a1, a2), b2 + 1), c0_end = b1; c0 <= c0_end; c0 += 1)
    for (int c1_0 = c1, c1_0_end = d1; c1_0 <= c1_0_end; c1_0 += 1)
      s0(c0, c1_0);
}
