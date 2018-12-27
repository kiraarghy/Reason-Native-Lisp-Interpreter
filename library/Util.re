let foo = (boo: string) => print_endline(boo);

let parse = () =>
  Arg.parse(
    [("-string", Arg.String(Parser.parse), "print word")],
    print_endline,
    "boop",
  );