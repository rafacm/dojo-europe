module ComposableMap = {
  [@bs.module "react-simple-maps"]
  external myJSReactClass : ReasonReact.reactClass = "ComposableMap";

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

module Marker = {
  [@bs.deriving abstract]
  type t = {
    markerOffset: int,
    name: string,
    coordinates: array(float),
  };
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

module Styles = {
  [@bs.deriving abstract]
  type t = {
    default: ReactDOMRe.style,
    hover: ReactDOMRe.style,
    pressed: ReactDOMRe.style,
  };
  let make = t;
};

module GeographyComponent = {
  [@bs.module "react-simple-maps"]
  external myJSReactClass : ReasonReact.reactClass = "Geography";

  module Props = {
    [@bs.deriving abstract]
    type t = {
      geography: Geography.t,
      projection: Projection.t,
      style: Styles.t,
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

module Markers = {
  [@bs.module "react-simple-maps"]
  external myJSReactClass : ReasonReact.reactClass = "Markers";

  module Props = {
    [@bs.deriving abstract]
    type t = {geography: string};
    let make = t;
  };

  type childrenType = array(Marker.t) => array(ReasonReact.reactElement);

  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass=myJSReactClass,
      ~props=Js.Obj.empty(),
      children,
    );
};

module MarkerComponent = {
  [@bs.module "react-simple-maps"]
  external myJSReactClass : ReasonReact.reactClass = "Marker";

  module Props = {
    [@bs.deriving abstract]
    type t = {
      marker: Marker.t,
      style: Styles.t,
    };
    let make = t;
  };

  let make = (~marker, ~style, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=myJSReactClass,
      ~props=Props.make(~marker, ~style),
      children,
    );
};