module ComposableMap = {
  [@bs.module "react-simple-maps"]
  external myJSReactClass : ReasonReact.reactClass = "ComposableMap";

  /*
   projectionConfig={{
             scale: 205,
             rotation: [-11,0,0],
           }}
           width={980}
           height={551}
           style={{
             width: "100%",
             height: "auto",
           }}
   */

  module ProjectionConfig = {
    [@bs.deriving abstract]
    type t = {
      scale: int,
      rotation: array(int),
    };
    let make = t;
  };

  module Props = {
    [@bs.deriving abstract]
    type t = {
      projectionConfig: ProjectionConfig.t,
      width: int,
      height: int,
      [@bs.optional]
      style: ReactDOMRe.style,
    };
    let make = t;
  };

  let make = (~projectionConfig, ~width, ~height, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=myJSReactClass,
      ~props=Props.make(~projectionConfig, ~width, ~height, ~style?, ()),
      children,
    );
};

module ZoomableGroup = {
  [@bs.module "react-simple-maps"]
  external myJSReactClass : ReasonReact.reactClass = "ZoomableGroup";

  module Props = {
    [@bs.deriving abstract]
    type t = {
      center: array(int),
      disablePanning: bool,
    };
    let make = t;
  };

  let make = (~center, ~disablePanning, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=myJSReactClass,
      ~props=Props.make(~center, ~disablePanning),
      children,
    );
};