// Generated by BUCKLESCRIPT VERSION 3.1.4, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var ReactSimpleMaps = require("./ReactSimpleMaps.bs.js");

var component = ReasonReact.statelessComponent("Main");

var myStyle = {
  height: "auto",
  width: "100%"
};

var projectionConfig = Curry._2(ReactSimpleMaps.ComposableMap[/* ProjectionConfig */0][/* make */0], 205, /* array */[
      -11,
      0,
      0
    ]);

function make() {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("div", undefined, React.createElement("h1", undefined, "hello"), React.createElement("div", undefined, ReasonReact.element(/* None */0, /* None */0, ReactSimpleMaps.ComposableMap[/* make */2](projectionConfig, 980, 551, /* Some */[myStyle], /* array */[ReasonReact.element(/* None */0, /* None */0, ReactSimpleMaps.ZoomableGroup[/* make */0](/* array */[]))]))));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.component = component;
exports.myStyle = myStyle;
exports.projectionConfig = projectionConfig;
exports.make = make;
/* component Not a pure module */
