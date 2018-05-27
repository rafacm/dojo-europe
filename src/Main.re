open ReactSimpleMaps;

let component = ReasonReact.statelessComponent("Main");

let myStyle = ReactDOMRe.Style.make(~width="100%", ~height="auto", ());
let geographyComponentStyle =
  ReactDOMRe.Style.make(~width="100%", ~height="auto", ());

let geographyStyles =
  ReactSimpleMaps.GeographyComponent.Style.make(
    ~default=
      ReactDOMRe.Style.make(
        ~fill="#ECEFF1",
        ~stroke="#607D8B",
        ~strokeWidth="0.75",
        ~outline="none",
        (),
      ),
    ~hover=
      ReactDOMRe.Style.make(
        ~fill="#607D8B",
        ~stroke="#607D8B",
        ~strokeWidth="0.75",
        ~outline="none",
        (),
      ),
    ~pressed=
      ReactDOMRe.Style.make(
        ~fill="#FF5722",
        ~stroke="#607D8B",
        ~strokeWidth="0.75",
        ~outline="none",
        (),
      ),
  );
let projectionConfig =
  ComposableMap.ProjectionConfig.make(~scale=205, ~rotation=[|(-11), 0, 0|]);

let mapGeographies = (geographies, projection) =>
  Belt.Array.mapWithIndex(geographies, (i, geography) =>
    <GeographyComponent
      key=(string_of_int(i))
      geography
      projection
      style=geographyStyles
    />
  );

let fetchUsers = () => {
  Js.log("hello!");
  Fetcher.fetchGet(
    ~url="https://immense-river-25513.herokuapp.com/locations", ~cb=users =>
    Js.log2("users", users)
  );
};

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h1> (ReasonReact.string("Dojo Vienna")) </h1>
      <div>
        <ComposableMap projectionConfig width=980 height=551 style=myStyle>
          <ZoomableGroup center=[|0, 20|] disablePanning=true>
            <Geographies geography="/world-50m.json">
              ...mapGeographies
            </Geographies>
          </ZoomableGroup>
        </ComposableMap>
      </div>
    </div>,
  didMount: self => {
    Fetcher.fetchPost(
      ~url="https://immense-river-25513.herokuapp.com/add-location",
      ~body="rafacm",
    );
    fetchUsers();
    let intervalId = Js.Global.setInterval(fetchUsers, 30000);
    self.onUnmount(() => Js.Global.clearInterval(intervalId));
  },
};