print_endline("tokeniser matches output");

print_endline("When `()` it equals `(`, ``, `)`");

print_endline(
  string_of_bool(EsyPesyStarter.Parser.tokeniser("()") == ["(", "", ")"]),
);

print_endline("When `(x)` it equals `(`, `x`, `)`");

print_endline(
  string_of_bool(EsyPesyStarter.Parser.tokeniser("(x)") == ["(", "x", ")"]),
);

print_endline("When `(lisp)` it equals `(`, `lisp`, `)`");

print_endline(
  string_of_bool(EsyPesyStarter.Parser.tokeniser("(lisp)") == ["(", "lisp", ")"]),
);