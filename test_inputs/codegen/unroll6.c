{
  if (g >= 0 && nn >= 128 * g + 6 && nn >= ((t1 + 127) % 128) + 128 * g + 3)
    for (int c1 = 393214, c1_end = nn - 1; c1 < c1_end; c1 += 393216)
      A(c1, ((t1 + 127) % 128) + 128 * g + 1, ((t1 + 127) % 128) + 1);
  if (t1 >= 1 && t1 <= 2 && nn >= t1 + 128 * g + 130 && t1 + 128 * g >= -127)
    for (int c1 = 393214, c1_end = nn - 1; c1 < c1_end; c1 += 393216)
      A(c1, t1 + 128 * g + 128, t1 + 128);
}
