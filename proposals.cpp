int foo(int x) {
  if (x == 0) { return 0; }
  // My style: allowed.
  // clang-format: Wraps it because AllowShortBlocksOnASingleLine is not set,
  //   because I don't want to allow:  if (x == 0)
  //                                   { yuck = true; }
  // Proposal 1: Add AllowShortIfAndBlockOnASingleLine to allow compressing the
  //   if and the block if the *whole thing* fits on one line.
  // Proposal 2: Make AllowShortBlocksOnASingleLine not apply to blocks in the
  //   if statement; those blocks can only be single-line if the the entire if
  //   gets onto one line.

  if (x == 1) {
    return 1;
  }
  // My style: allowed.
  // clang-format 5.0.0: Currently allows it, but might not if I fix the above.
  // Proposal:  Allow should mean allowed, not forced.  There are subjective
  // considerations like how likely the programmer is to add new lines to the
  // block or consistency with nearby code.

  if (x == 4) return 1;
  // My style: not allowed, missing braces.
  // clang-format: Currently allows it.
  // Proposal: Add AllowIfWithNoBraces

  // Proposal: Do the same thing for for, while, and do-while.

  return 10 / x;
}
