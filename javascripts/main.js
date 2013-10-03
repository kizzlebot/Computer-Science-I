
var canvas = document.getElementById('canvas');
var context = canvas.getContext('2d');
var divisor = {
  x:0, 
  y:0
}; 
var div ={
  x:canvas.width,
  y:canvas.height
};
function getGuesstimate(canvasSize){
  divisor = {
    x:0,
    y:0
  };
  for ( var i = 25 ; i > 0 ; i--){
    if ( canvasSize.x%i===0){
      divisor.x = i;
      break;
    }
  }
  for ( var j = 25 ; j > 0 ; j--){
    if (canvasSize.y%i === 0 ){
      divisor.y=j;
      break;
    }
  }
  div.x = divisor.x;
  div.y = divisor.y;
  console.log(div.x+" "+div.y);
  return divisor;
}
function getDotCoord(clickPos,div){
  var i = 0 ;
  for ( i = 0 ; i < clickPos.x ; i+=div.x){}
  clickPos.x = i-(div.x/2);
  for ( i = 0 ; i < clickPos.y ; i+=div.y){}
  clickPos.y = i-(div.y/2);

  return clickPos;
}

function getMousePos(canvas,event){
  var rect = canvas.getBoundingClientRect();
  return {
    x: event.clientX - rect.left,
    y: event.clientY - rect.top
  };
}

function drawGuide(canvasSize){  
  div = getGuesstimate(canvasSize);
  for ( var k = 0 ; k < canvasSize.x ; k=k+div.x){
    $("canvas").drawLine({
      strokeStyle: "#000",
      strokeWidth: 0.5,
      x1: k, y1: 0,
      x2: k, y2: canvasSize.y
      });
 
  } 
  
  for ( l = 0 ; l < canvasSize.y ; l=l+div.y){
    $("canvas").drawLine({
      strokeStyle: "#000",
      strokeWidth: 0.5,
      x1: 0, y1: l,
      x2: canvasSize.x, y2:l
    });
  }
}

canvas.addEventListener('mousedown', function(evt) {
  var mousePos = getMousePos(canvas, evt);
  var message = 'Mouse position: ' + mousePos.x + ',' + mousePos.y;

  div = getGuesstimate(div);
  mousePos = getDotCoord(mousePos,div);
  $("canvas").drawArc({
          fillStyle: "#FFF",
          x: mousePos.x, y: mousePos.y,
          radius: (div.x-2.5)/2
  });
}, false);

w ={
    x:canvas.width,
    y:canvas.height
}; 

drawGuide(w);
