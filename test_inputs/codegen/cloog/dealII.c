{
  if (T_67 == 0 && T_66 <= -1) {
    S1(0);
  } else if (T_2 >= 1 && T_67 >= 1 && T_66 <= -1) {
    S1(0);
  } else if (T_2 >= 1 && T_67 >= 1 && T_66 >= 0) {
    S1(0);
    S2(0);
  }
  for (int c0 = 1, c0_end = min(min(T_2 - 1, T_67 - 1), T_66); c0 <= c0_end; c0 += 1) {
    S1(c0);
    S2(c0);
  }
  for (int c0 = max(1, T_66 + 1), c0_end = min(T_2, T_67); c0 < c0_end; c0 += 1)
    S1(c0);
  if (T_2 >= 1 && T_67 == 0 && T_66 >= 0) {
    S1(0);
    S2(0);
  }
  for (int c0 = max(1, T_67), c0_end = min(T_2 - 1, T_66); c0 <= c0_end; c0 += 1) {
    S1(c0);
    S2(c0);
  }
  for (int c0 = max(max(1, T_67), T_66 + 1), c0_end = T_2; c0 < c0_end; c0 += 1)
    S1(c0);
  if (T_2 == 0 && T_67 >= 1 && T_66 >= 0)
    S2(0);
  for (int c0 = max(1, T_2), c0_end = min(T_67 - 1, T_66); c0 <= c0_end; c0 += 1)
    S2(c0);
  if (T_2 == 0 && T_67 == 0 && T_66 >= 0)
    S1(0);
}
