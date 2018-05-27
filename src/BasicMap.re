[@bs.module "./BasicMap"]
external myJSReactClass : ReasonReact.reactClass = "default";

let make = children =>
  ReasonReact.wrapJsForReason(
    ~reactClass=myJSReactClass,
    ~props=Js.Obj.empty(),
    children,
  );