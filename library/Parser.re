open String;
open Str;
type catergorizedtypes = {
  typelisp: string,
  value: string,
};

type listOfCatergories = list(catergorizedtypes);

let catergorize = (input: string) =>
  string_match(regexp("\\-?\\d+"), input, 0) ?
    {typelisp: "item", value: input} :
    string_match(regexp("\\(\"\\)"), input, 0) ?
      {typelisp: "literal", value: "\""} :
      {typelisp: "identifier", value: input};

let tokeniser = input =>
  input
  |> global_replace(regexp("\\((\\)"), " ( ")
  |> global_replace(regexp("\\()\\)"), " ) ")
  |> trim
  |> split(regexp("\\(s\\)"));

let rec parenthesise = (accumulator: listOfCatergories, tokenisedInput) =>
  switch (List.hd(tokenisedInput)) {
  | "(" =>
    parenthesise(
      List.append(accumulator, parenthesise([], List.tl(tokenisedInput))),
      List.tl(tokenisedInput),
    )
  | ")" => accumulator
  | _ =>
    parenthesise(
      List.append(accumulator, [catergorize(List.hd(tokenisedInput))]),
      List.tl(tokenisedInput),
    )
  };

let parse = (input: string) =>
  input |> tokeniser |> parenthesise([]);