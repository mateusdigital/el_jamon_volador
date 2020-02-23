//----------------------------------------------------------------------------//
// Kudos for https://github.com/nakardo                                       //
//                                                                            //
// I got everything from here:                                                //
//    https://www.npmjs.com/package/node-gameboy                              //
//                                                                            //
// And modify a little to remove the dependencies of jquery                   //
//----------------------------------------------------------------------------//
var gameboy = window.gameboy = new (window.Gameboy)();

// Render
var canvas = document.getElementById('frame');

var ctx = canvas.getContext('2d');
gameboy.gpu.on('frame', function (offcanvas) {
    ctx.drawImage(offcanvas, 0, 0);
});

// Load rom
fetch(new Request('./flappy.gb'))
    .then(response => response.arrayBuffer())
    .then(function (buffer) {
        gameboy.loadCart(buffer);
        gameboy.start();
    });

function loadFile () {
    if (!this.files.length) return;

    var reader = new FileReader();
    reader.onloadend = function () {
        gameboy.loadCart(reader.result);
        gameboy.start();
    };
    reader.readAsArrayBuffer(this.files[0]);
}

// Joypad
document.onkeydown  = function(e) { gameboy.joypad.keyDown(e.keyCode) }
document.onkeyup    = function(e) { gameboy.joypad.keyUp  (e.keyCode) }
