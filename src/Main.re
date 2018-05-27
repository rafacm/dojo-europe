open ReactSimpleMaps;

let component = ReasonReact.statelessComponent("Main");

let myStyle = ReactDOMRe.Style.make(~width="100%", ~height="auto", ());

let projectionConfig =
  ComposableMap.ProjectionConfig.make(~scale=205, ~rotation=[|(-11), 0, 0|]);
let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h1> (ReasonReact.string("hello")) </h1>
      <div>
        <ComposableMap projectionConfig width=980 height=551 style=myStyle>
          <ZoomableGroup />
        </ComposableMap>
      </div>
    </div>,
};