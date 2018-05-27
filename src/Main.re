let component = ReasonReact.statelessComponent("Main");

let make = _children => {
  ...component,
  render: _self => <div> (ReasonReact.string("hello")) </div>,
};