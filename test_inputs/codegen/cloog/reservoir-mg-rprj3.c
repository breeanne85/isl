if (M >= 2 && N >= 3)
  for (int c0 = 2, c0_end = O; c0 < c0_end; c0 += 1) {
    for (int c2 = 2, c2_end = M; c2 <= c2_end; c2 += 1)
      S1(c0, 2, c2);
    for (int c1 = 3, c1_end = N; c1 < c1_end; c1 += 1) {
      for (int c2 = 2, c2_end = M; c2 <= c2_end; c2 += 1)
        S2(c0, c1 - 1, c2);
      if (M >= 3)
        S4(c0, c1 - 1, 2);
      for (int c2 = 2, c2_end = M - 1; c2 < c2_end; c2 += 1) {
        S3(c0, c1 - 1, c2);
        S5(c0, c1 - 1, c2);
        S4(c0, c1 - 1, c2 + 1);
      }
      if (M >= 3) {
        S3(c0, c1 - 1, M - 1);
        S5(c0, c1 - 1, M - 1);
      }
      for (int c2 = 2, c2_end = M; c2 <= c2_end; c2 += 1)
        S1(c0, c1, c2);
    }
    for (int c2 = 2, c2_end = M; c2 <= c2_end; c2 += 1)
      S2(c0, N - 1, c2);
    if (M >= 3)
      S4(c0, N - 1, 2);
    for (int c2 = 2, c2_end = M - 1; c2 < c2_end; c2 += 1) {
      S3(c0, N - 1, c2);
      S5(c0, N - 1, c2);
      S4(c0, N - 1, c2 + 1);
    }
    if (M >= 3) {
      S3(c0, N - 1, M - 1);
      S5(c0, N - 1, M - 1);
    }
  }
