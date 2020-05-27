//----------------------------------------------------------------------------//
// Kudos for https://github.com/nakardo                                       //
//                                                                            //
// I got everything from here:                                                //
//    https://www.npmjs.com/package/node-gameboy                              //
//                                                                            //
// And modify a little to remove the dependencies of jquery                   //
//----------------------------------------------------------------------------//
const ROM_FILENAME       = "./rom/game.gb"
const ACTION_BUTTON_CODE = 88;

var gameboy = window.gameboy = new (window.Gameboy)();

//
// Render
var canvas = document.getElementById('frame');
var ctx    = canvas.getContext('2d');

canvas.style.width  = "100%";
canvas.style.height = "100%";

gameboy.gpu.on('frame', function (offcanvas) {
    console.log(offcanvas.width, offcanvas.height);
    ctx.drawImage(offcanvas, 0, 0);
});

//
// Load rom
fetch(new Request(ROM_FILENAME))
    .then(response => response.arrayBuffer())
    .then(function (buffer) {
        gameboy.loadCart(buffer);
        gameboy.start();
    });


//
// Joypad
document.onkeydown = function(e) {
    gameboy.joypad.keyDown(ACTION_BUTTON_CODE);
}
document.onkeyup = function(e) {
    gameboy.joypad.keyUp(ACTION_BUTTON_CODE);
}

canvas.addEventListener("mousedown", (e)=>{
    e.preventDefault()
    gameboy.joypad.keyDown(ACTION_BUTTON_CODE);
}, false);

canvas.addEventListener("mouseup", (e)=>{
    e.preventDefault()
    gameboy.joypad.keyUp(ACTION_BUTTON_CODE);
}, false);


canvas.addEventListener("touchstart", (e)=>{
    e.preventDefault()
    gameboy.joypad.keyDown(ACTION_BUTTON_CODE);
}, false);

canvas.addEventListener("touchend", (e)=>{
    e.preventDefault()
    gameboy.joypad.keyUp(ACTION_BUTTON_CODE);
}, false);
