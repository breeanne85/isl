if (M >= 0 && N >= 0)
  for (int c0 = -4, c0_end = 3 * M + N; c0 <= c0_end; c0 += 1) {
    if (c0 >= 0 && 3 * M + 1 >= c0 && (c0 + 1) % 3 >= 1 && N + 1 >= (c0 + 1) % 3)
      S2((c0 + 1) / 3, ((c0 + 1) % 3) - 1);
    for (int c1 = max(-3 * M + c0 - 2, (c0 + 4) % 3), c1_end = min(min(N - 2, c0 - 2), -3 * M + c0 + 3); c1 <= c1_end; c1 += 3)
      S2((c0 - c1 - 2) / 3, c1 + 2);
    for (int c1 = max(-3 * M + c0 + 4, (c0 + 4) % 3), c1_end = min(N - 1, c0 - 1); c1 < c1_end; c1 += 3) {
      S1((c0 - c1 + 4) / 3, c1);
      S2((c0 - c1 - 2) / 3, c1 + 2);
    }
    if (3 * M + N >= c0 + 4 && c0 >= N + 1 && ((-N + c0) % 3) + N >= 2 && (-N + c0) % 3 >= 1)
      S1((-N + c0 + 3) / 3 + 1, ((-N + c0) % 3) + N - 2);
    for (int c1 = max(max(c0 + 1, -3 * M + c0 + 4), (c0 + 4) % 3), c1_end = min(N, c0 + 4); c1 <= c1_end; c1 += 3)
      S1((c0 - c1 + 4) / 3, c1);
    for (int c1 = max(-3 * M + c0, (c0 + 6) % 3), c1_end = min(N, c0); c1 <= c1_end; c1 += 3)
      S3((c0 - c1) / 3, c1);
  }
