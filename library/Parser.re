open String;
open Str;

type catergorizedtypes = {
  typelisp: string,
  value: string,
};

type listOfCatergories = list(catergorizedtypes);

let catergorize = (input: string) =>
  switch (int_of_string(input)) {
  | exception (Failure("float_of_string")) =>
    if (input.[0] === '"') {
      {typelisp: "token", value: ""};
    } else {
      {typelisp: "boo", value: "3"};
    }
  | _ => {typelisp: "literal", value: input}
  };

let tokeniser = input =>
  input
  |> global_replace(regexp("\\((\\)"), " ( ")
  |> global_replace(regexp("\\()\\)"), " ) ")
  |> trim
  |> split(regexp("\\(s\\)"));

let rec parenthesise = (list: listOfCatergories, input: list(string)) =>
  switch (List.hd(input)) {
  | "(" =>
    parenthesise(
      List.append(list, parenthesise([], List.tl(input))),
      List.tl(input),
    )
  | ")" => list
  | _ =>
    parenthesise(
      List.append(list, [catergorize(List.hd(input))]),
      List.tl(input),
    )
  };

let parse = (input: string) =>
  tokeniser |> parenthesise([]) |> print_endline;