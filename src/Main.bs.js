// Generated by BUCKLESCRIPT VERSION 3.1.4, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Fetcher = require("./Fetcher.bs.js");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var ReactSimpleMaps = require("./ReactSimpleMaps.bs.js");

var component = ReasonReact.reducerComponent("Main");

var myStyle = {
  height: "auto",
  width: "100%"
};

var geographyComponentStyle = {
  height: "auto",
  width: "100%"
};

console.log("sfsdffsdfsd");

var geographyStyles = ReactSimpleMaps.Styles[/* make */0]({
      outline: "none",
      fill: "#ECEFF1",
      stroke: "#607D8B",
      strokeWidth: "0.75"
    }, {
      outline: "none",
      fill: "#607D8B",
      stroke: "#607D8B",
      strokeWidth: "0.75"
    }, {
      outline: "none",
      fill: "#FF5722",
      stroke: "#607D8B",
      strokeWidth: "0.75"
    });

var markerStyles = ReactSimpleMaps.Styles[/* make */0]({
      fill: "#FF5722"
    }, {
      fill: "#FFFFFF"
    }, {
      fill: "#FF5722"
    });

var projectionConfig = Curry._2(ReactSimpleMaps.ComposableMap[/* ProjectionConfig */0][/* make */0], 205, /* array */[
      -11,
      0,
      0
    ]);

function mapGeographies(geographies, projection) {
  return Belt_Array.mapWithIndex(geographies, (function (i, geography) {
                return ReasonReact.element(/* Some */[String(i)], /* None */0, ReactSimpleMaps.GeographyComponent[/* make */1](geography, projection, geographyStyles, /* array */[]));
              }));
}

function mapMarkers(markers) {
  return Belt_Array.mapWithIndex(markers, (function (i, marker) {
                return ReasonReact.element(/* Some */[String(i)], /* None */0, ReactSimpleMaps.MarkerComponent[/* make */1](marker, markerStyles, /* array */[]));
              }));
}

function fetchUsers(self) {
  return Fetcher.fetchGet("https://immense-river-25513.herokuapp.com/locations", (function (users) {
                return Curry._1(self[/* send */3], /* UsersFetched */[users]);
              }));
}

function userToMarker(user) {
  var match = user.location;
  return ReactSimpleMaps.Marker[/* make */0](/* array */[
              match[1],
              match[0]
            ]);
}

function make() {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */(function (self) {
              Fetcher.fetchPost("https://immense-river-25513.herokuapp.com/add-location", "rafacm");
              fetchUsers(self);
              var intervalId = setInterval((function () {
                      return fetchUsers(self);
                    }), 30000);
              return Curry._1(self[/* onUnmount */4], (function () {
                            clearInterval(intervalId);
                            return /* () */0;
                          }));
            }),
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (self) {
              var match = self[/* state */1][/* users */0];
              return React.createElement("div", undefined, React.createElement("h1", undefined, "Dojo Vienna"), React.createElement("div", undefined, ReasonReact.element(/* None */0, /* None */0, ReactSimpleMaps.ComposableMap[/* make */2](projectionConfig, 980, 551, /* Some */[myStyle], /* array */[ReasonReact.element(/* None */0, /* None */0, ReactSimpleMaps.ZoomableGroup[/* make */1](/* array */[
                                                0,
                                                20
                                              ], true, /* array */[
                                                ReasonReact.element(/* None */0, /* None */0, ReactSimpleMaps.Geographies[/* make */1]("/world-50m.json", mapGeographies)),
                                                match ? ReasonReact.element(/* None */0, /* None */0, ReactSimpleMaps.Markers[/* make */1](/* array */[Belt_Array.mapWithIndex(match[0], (function (i, user) {
                                                                    return ReasonReact.element(/* Some */[String(i)], /* None */0, ReactSimpleMaps.MarkerComponent[/* make */1](userToMarker(user), markerStyles, /* array */[
                                                                                    React.createElement("circle", {
                                                                                          style: {
                                                                                            opacity: "0.9",
                                                                                            stroke: "#FF5722",
                                                                                            strokeWidth: "3"
                                                                                          },
                                                                                          cx: "0",
                                                                                          cy: "0",
                                                                                          r: "2"
                                                                                        }),
                                                                                    React.createElement("text", {
                                                                                          style: {
                                                                                            fontFamily: "Roboto, sans-serif",
                                                                                            fontSize: "11px",
                                                                                            fill: "607D8B"
                                                                                          },
                                                                                          textAnchor: "middle",
                                                                                          y: "-10"
                                                                                        }, user.username)
                                                                                  ]));
                                                                  }))])) : null
                                              ]))]))));
            }),
          /* initialState */(function () {
              return /* record */[/* users : None */0];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, _) {
              return /* Update */Block.__(0, [/* record */[/* users : Some */[action[0]]]]);
            }),
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

var instance = /* record */[
  /* a */2,
  /* b */"sdfj"
];

exports.instance = instance;
exports.component = component;
exports.myStyle = myStyle;
exports.geographyComponentStyle = geographyComponentStyle;
exports.geographyStyles = geographyStyles;
exports.markerStyles = markerStyles;
exports.projectionConfig = projectionConfig;
exports.mapGeographies = mapGeographies;
exports.mapMarkers = mapMarkers;
exports.fetchUsers = fetchUsers;
exports.userToMarker = userToMarker;
exports.make = make;
/* component Not a pure module */
