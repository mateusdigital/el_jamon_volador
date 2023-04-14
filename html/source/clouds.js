//
// Functions
//

//------------------------------------------------------------------------------
// The logic to draw the clouds is the following:
//   - Draw a big circle.
//   - From a range of angles, select a random size
//   - Draw circle of that size on that position.
function _make_cloud(div, color) {
    // @perf: We could optimize this b y using the same canvas??
    // Cleaning the rect is faster that creating another? - abr 14, 2023
    const canvas = document.createElement("canvas");
    const ctx    = canvas.getContext("2d");

    // Space that we can draw.
    const div_width  = div.clientWidth;
    const div_height = div.clientHeight;

    canvas.width  = div_width;
    canvas.height = div_height;

    const center_radius   = 60 + (Math.random() * 30);
    const total_clouds    = Math.trunc(div_width / center_radius) + 1; // Draw many clouds as need to fill the screen.
    const total_subclouds = 8 + (Math.random() * 4);

    for (let cloud_i = 0; cloud_i < total_clouds; ++cloud_i) {
        ctx.fillStyle = color;

        ctx.save();
        ctx.translate(
            (cloud_i + 1) * center_radius + center_radius * cloud_i,
            center_radius * 1.8 // Draw a little do the botton.
        );

        // Bigger circle.
        ctx.beginPath();
            ctx.arc(0, 0, center_radius, 0, 2 * Math.PI);
        ctx.fill();

        for (let subcloud_i = 0; subcloud_i < total_subclouds; ++subcloud_i) {
            ctx.fillStyle = color;

            const x = -Math.cos(subcloud_i) * center_radius;
            const y = -Math.sin(subcloud_i) * center_radius;

            let v = Math.random();
            v = Math.max(v, 0.2);
            v = Math.min(v, 0.8);

            const r = (v * center_radius);

            ctx.beginPath();
                ctx.arc(x, y, r, 0, 2 * Math.PI);
            ctx.fill();
        }
        ctx.restore();
    }

    const dataURL = canvas.toDataURL();
    div.style.backgroundImage = `url(${dataURL})`;
}

//------------------------------------------------------------------------------
function _make_all_clouds()
{
    let background_colors = [
        "#6198bb",
        "#8ab4cf",
        "#b8d7eb",
        "#ddedfa",
    ]

    let foreground_colors = [
        "#ffffff",
        "#f9f9f9",
    ]


    if(false) {
         background_colors = [
            "red", "green", "blue", "yellow",
        ]

         foreground_colors = [
            "magenta", "cyan"
        ]
    }



    const background_divs = document.querySelectorAll(".cloud-background");
    for(let i = 0; i < background_divs.length; ++i) {
        const element = background_divs  [i];
        const color   = background_colors[i];

        _make_cloud(element, color);

        const pos         = (element.clientHeight * 0.25 * i);
        element.style.top = `${pos}px`;

        // Controls the animation in CSS.
        const duration = Math.floor(Math.random() * 10) + 10;
        const delay    = Math.floor(Math.random() * 3 ) +  1;

        element.style.setProperty("--delay",    `${delay}s`   );
        element.style.setProperty("--duration", `${duration}s`);
    }

    const foreground_divs = document.querySelectorAll(".cloud-foreground");
    for(let i = 0; i < foreground_divs.length; ++i) {
        const element = foreground_divs  [i];
        const color   = foreground_colors[i];

        _make_cloud(element, color);

        const pos         = (element.clientHeight * 0.25 * i);
        element.style.top = `${pos}px`;

        // Controls the animation in CSS.
        const duration = Math.floor(Math.random() * 10) + 10;
        const delay    = Math.floor(Math.random() * 3 ) +  1;

        element.style.setProperty("--delay",    `${delay}s`   );
        element.style.setProperty("--duration", `${duration}s`);
    }
}