<script src="./modules/external/gameboy/src/cpu.js" defer></script>
<script src="./modules/external/gameboy/src/ops.js" defer></script>
<script src="./modules/external/gameboy/src/mem.js" defer></script>
<script src="./modules/external/gameboy/src/ppu.js" defer></script>
<script src="./modules/external/gameboy/src/apu.js" defer></script>
<script src="./modules/external/gameboy/src/joypad.js" defer></script>
<script src="./modules/external/gameboy/src/main.js" defer></script>



window.onload = function () {
    const canvas = document.getElementById('nanacanvas');
    const gb = new Gameboy();
    gb.AttachCanvas(canvas);

    // Default settings
    gb.SetFPS(60); // 120 is performant but 60 is smoother
    gb.bootromEnabled = false;
    gb.SetPallete(['fff6d3', 'f9a875', 'eb6b6f', '7c3f58']);

    // const defaultVolume = 0.05;
    // gb.SetVolume (defaultVolume);
    // gb.EnableSound ();

    gb.DisableAlphaBlend();
    gb.SetAlphaBlend(0.7);

    gb.keyboardEnabled = true;

    fetch("./rom/el-jamon-volador_1.2.0.gb")
        .then(response => response.blob())
        .then(blob => {
            const fileReader = new FileReader();

            fileReader.onload = () => {
                const fileData = new Uint8Array(fileReader.result);
                gb.InsertRom(fileData);
                gb.Start();
            };
            fileReader.readAsArrayBuffer(blob);
        })
        .catch(error => {
            console.error(error);
        });
}