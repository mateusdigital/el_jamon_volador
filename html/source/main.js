const ROM_FILENAME       = "./rom/game.gb"


// Then, create a Gameboy object !
const gb = new Gameboy();
gb.AttachCanvas(canvas); // ; Attach to canvas of choice

// Here are some default settings I use ...
gb.SetFPS (60);
gb.bootromEnabled = false;
gb.SetVolume (0.05);
gb.EnableSound ();
gb.keyboardEnabled = true;



// Finally, you load roms and start the GB !
any_file_input_or_sumn.onchange = function () {
    // Load a binary buffer from file input ...
    // And then ... fun taim :D
    gb.InsertRom (binBuffer);
    gb.Start ();
};

//
// Render
var canvas = document.getElementById('frame');
var ctx    = canvas.getContext('2d');

canvas.style.width  = "100%";
canvas.style.height = "100%";

gameboy.gpu.on('frame', function (offcanvas) {
    debugger
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
