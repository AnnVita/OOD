let Application = React.createClass({
    render: function() {
        return (
            <div className="container">
                <Canvas />
                <ShapeControl />
            </div>
        );
    }
});


let Canvas = React.createClass({
    render() {
        return (
            <canvas height='500' width='700' className='canvas' id='canvas'>No HTML5</canvas>
        );
    }
});

let ShapeControl = React.createClass({
    render() {
        return (
            <div className="shape-control">
                    <ShapeSelect />
                    <ColorParameters />
                    <ShapeProperties />
                    <ShapeInfo />
            </div>
        );
    }
});

let ShapeSelect = React.createClass({
    render() {
        return (
            <select className='shape-select' id='shape-select' name='shape-select'>
               <option selected disabled>Choose shape</option>
               <option value='rectangle'>Rectangle</option>
               <option value='triangle'>Triangle</option>
               <option value='circle'>Circle</option>
            </select>
        );
    }
});

let ColorParameters = React.createClass({
    render() {
        return (
             <div className='color-parameters' id='color-parameters'>
                <div className='property'>
                    <div className='property-signature'>Fill color:</div>
                   <input type='text' className='input-text' placeholder='#FFFFFF' defaultValue='#00FF00' id='fill-color' />
                </div>
                <div className='property'>
                   <div className='property-signature'>Border color:</div>
                   <input type='text' className='input-text' placeholder='#FFFFFF' defaultValue='#0000FF' id='border-color' />
                </div>
             </div>
        );
    }
});

let ShapeProperties = React.createClass({
    render() {
        return (
            <div className='shape-information'>
                <RectangleProperties />
                <TriangleProperties />
                <CircleProperties />
            </div>
        );
    }
});

let RectangleProperties = React.createClass({
    render() {
        return (
            <div className='shape-parameters' id='rectangle-parameters'>
              <div className='property'>
                <div className='property-signature'>X coordinate:</div>
                <input type='text' placeholder='0' defaultValue='20' className='input-text' id='rectangle-x' />
              </div>
              <div className='property'>
                <div className='property-signature'>Y coordinate:</div>
                <input type='text' placeholder='0' defaultValue='20' className='input-text' id='rectangle-y' />
              </div>
              <div className='property'>
                <div className='property-signature'>Width:</div>
                <input type='text' placeholder='0' defaultValue='200' className='input-text' id='rectangle-width' />
              </div>
              <div className='property'>
                <div className='property-signature'>Height:</div>
                <input type='text' placeholder='0' defaultValue='100' className='input-text' id='rectangle-height' />
              </div>
            </div>
        );
    }
});

let TriangleProperties = React.createClass({
    render() {
        return (
                    <div className='shape-parameters' id='triangle-parameters'>
          <div className='property'>
            <div className='property-signature'>First x:</div>
            <input type='text' placeholder='0' defaultValue='10' className='input-text' id='first-x' />
          </div>
          <div className='property'>
            <div className='property-signature'>First y:</div>
            <input type='text' placeholder='0' defaultValue='10' className='input-text' id='first-y' />
          </div>
          <div className='property'>
            <div className='property-signature'>Second x:</div>
            <input type='text' placeholder='0' defaultValue='400' className='input-text' id='second-x' />
          </div>
          <div className='property'>
            <div className='property-signature'>Second y:</div>
            <input type='text' placeholder='0' defaultValue='400' className='input-text' id='second-y' />
          </div>
          <div className='property'>
            <div className='property-signature'>Third x:</div>
            <input type='text' placeholder='0' defaultValue='10' className='input-text' id='third-x' />
          </div>
          <div className='property'>
            <div className='property-signature'>Third y:</div>
            <input type='text' placeholder='0' defaultValue='100' className='input-text' id='third-y' />
          </div>
        </div>
        );
    }
});

let CircleProperties = React.createClass({
    render() {
        return (
            <div className='shape-parameters' id='circle-parameters'>
          <div className='property'>
            <div className='property-signature'>Center x:</div>
            <input type='text' placeholder='0' defaultValue='200' className='input-text' id='circle-x' />
          </div>
          <div className='property'>
            <div className='property-signature'>Center y:</div>
            <input type='text' placeholder='0' defaultValue='200' className='input-text' id='circle-y' />
          </div>
          <div className='property'>
            <div className='property-signature'>Radius:</div>
            <input type='text' placeholder='0' defaultValue='100' className='input-text' id='circle-radius' />
          </div>
        </div>
        );
    }
});

let ShapeInfo = React.createClass({
    render() {
        return (
            <div className='shape-info' id='shape-info'>
              I have no info now:(
            </div>
        ); 
    }
});

ReactDOM.render(<Application />, document.getElementById('application'));
