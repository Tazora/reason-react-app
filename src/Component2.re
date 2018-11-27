/* State declaration */
type state = {
  count: int,
  show: bool,
  text: string,
};

/* Action declaration */
type action =
  | Click
  | Toggle
  | AddText;

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Example");

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = (~greeting, _children) => {
  /* spread the other default fields of component here and override a few */
  ...component,

  initialState: () => {count: 0, show: true, text: "Beispiel"},

  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({...state, count: state.count + 1})
    | Toggle => ReasonReact.Update({...state, show: ! state.show})
    | AddText => ReasonReact.Update({...state, text: state.text ++ "a"})
    },

  render: self => {
    let message =
      "You've clicked this " ++ string_of_int(self.state.count) ++ " times(s)";
    let text = self.state.text;
    <div>
      <button onClick=(_event => self.send(AddText))>
        (ReasonReact.string(self.state.text))
      </button>
      <br />
      <button onClick=(_event => self.send(Click))>
        (ReasonReact.string(message))
      </button>
      <br />
      <button onClick=(_event => self.send(Toggle))>
        (ReasonReact.string("Toggle greeting"))
      </button>
      <br />
      (self.state.show ? ReasonReact.string(greeting) : <Component3 text />)
    </div>;
  },
};
