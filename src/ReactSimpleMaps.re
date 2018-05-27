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

module Projection = {
  type t;
};

module Geography = {
  [@bs.deriving abstract]
  type t = {id: string};
  let make = t;
};

module Geographies = {
  [@bs.module "react-simple-maps"]
  external myJSReactClass : ReasonReact.reactClass = "Geographies";

  module Props = {
    [@bs.deriving abstract]
    type t = {geography: string};
    let make = t;
  };

  type childrenType =
    (array(Geography.t), Projection.t) => array(ReasonReact.reactElement);

  let make = (~geography, children: childrenType) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=myJSReactClass,
      ~props=Props.make(~geography),
      children,
    );
};

module GeographyComponent = {
  [@bs.module "react-simple-maps"]
  external myJSReactClass : ReasonReact.reactClass = "Geography";

  module Style = {
    [@bs.deriving abstract]
    type t = {
      default: ReactDOMRe.style,
      hover: ReactDOMRe.style,
      pressed: ReactDOMRe.style,
    };
    let make = t;
  };

  module Props = {
    [@bs.deriving abstract]
    type t = {
      geography: Geography.t,
      projection: Projection.t,
      style: Style.t,
    };
    let make = t;
  };

  let make = (~geography, ~projection, ~style, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=myJSReactClass,
      ~props=Props.make(~geography, ~projection, ~style),
      children,
    );
};