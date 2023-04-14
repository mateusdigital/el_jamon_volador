var gui = new dat.GUI();
const fg_colors   = [
    "#ffffff",
    "#ffffff",
]



function showColorPicker(color, i) {
    // Create an instance of the dat.GUI class


    // Add a color picker to the GUI
    var params = {
      color: color
    };
    var colorControl = gui.addColor(params, 'color');

      // When the user selects a color, log its value to the console
    colorControl.onChange(function(value) {
        fg_colors[i] = value;
        make_all();
    });
  }



function make_cloud(div, color) {
    const canvas = document.createElement("canvas");

    // debugger
    const div_width  = div.clientWidth;
    const div_height = div.clientHeight;

    canvas.width  = div_width;
    canvas.height = div_height;

    const center_radius   = 100;
    const total_clouds    = Math.trunc(div_width / center_radius) + 1;
    const total_subclouds = 8;

    const ctx = canvas.getContext('2d');

    for (let cloud_i = 0; cloud_i < total_clouds; ++cloud_i) {
        ctx.fillStyle = color;

        ctx.save();
        ctx.translate(
            (cloud_i + 1) * center_radius + center_radius * cloud_i,
            center_radius * 1.7
        );

        ctx.beginPath();
            ctx.arc(0, 0, center_radius, 0, 2 * Math.PI);
        ctx.fill();

        for (let subcloud_i = 0; subcloud_i < total_subclouds; ++subcloud_i) {
            // ctx.fillStyle = c[subcloud_i];
            ctx.fillStyle = color;

            const x = -Math.cos(subcloud_i) * center_radius;
            const y = -Math.sin(subcloud_i) * center_radius;

            let v = Math.random();
            v = Math.max(v, 0.2);
            v = Math.min(v, 0.8);

            const r = v * center_radius;

            ctx.beginPath();
                ctx.arc(x, y, r, 0, 2 * Math.PI);
            ctx.fill();
        }
        ctx.restore();
    }

    const dataURL = canvas.toDataURL();
    div.style.backgroundImage = `url(${dataURL})`;
}



function make_all(first_time)
{
    {
        const elements = document.querySelectorAll(".cloud-background");
        const colors   = [
            "#6198bb",
            "#8ab4cf",
            "#b8d7eb",
            "#ddedfa",
        ]

        for(let i = 0; i < elements.length; ++i) {
            const element = elements[i];
            const color   = colors  [i];
            console.log(i, color);

            make_cloud(element, color);

            const pos     = (element.clientHeight * 0.25 * i);
            element.style.top = `${pos}px`;
        }
    }

    {
        const elements = document.querySelectorAll(".cloud-foreground");


        for(let i = 0; i < elements.length; ++i) {
            const element = elements[i];
            const color   = fg_colors  [i];

            make_cloud(element, color);

            const pos     = (element.clientHeight * 0.25 * i);
            element.style.top = `${pos}px`;
        }
}
}

make_all(true);



const objects = document.querySelectorAll('.cloud-background');
objects.forEach((object) => {
    const delay = Math.floor(Math.random() * 3) + 1; // generate a random number between 1 and 3
    object.style.setProperty('--delay', `${delay}s`); // set the --delay property to the random value
});