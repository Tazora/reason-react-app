let component = ReasonReact.statelessComponent("Component3");
let make = (~text, _children) => {
  ...component,
  render: _self =>
    <div>
       <div className="Component3">
         (ReasonReact.string(text))
       </div>
    </div>,
};