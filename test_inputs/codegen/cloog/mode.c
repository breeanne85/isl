for (int c0 = 0, c0_end = M; c0 <= c0_end; c0 += 1) {
  for (int c1 = 0, c1_end = min(N, c0); c1 <= c1_end; c1 += 1) {
    S1(c0, c1);
    S2(c0, c1);
  }
  for (int c1 = max(0, N + 1), c1_end = c0; c1 <= c1_end; c1 += 1)
    S1(c0, c1);
  for (int c1 = c0 + 1, c1_end = N; c1 <= c1_end; c1 += 1)
    S2(c0, c1);
}
