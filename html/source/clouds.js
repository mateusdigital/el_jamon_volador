// const c = ["red", "blue", "green", "yellow", "magenta", "cyan"]

function make_cloud(div, color) {
    const canvas = document.createElement("canvas");

    // debugger
    const div_width = div.clientWidth;
    const div_height = div.clientHeight;

    canvas.width  = div_width;
    canvas.height = div_height;

    const center_radius = 100;
    const total_clouds    = Math.trunc(div_width / center_radius) + 1;
    const total_subclouds = 8;

    const ctx = canvas.getContext('2d');

    for (let cloud_i = 0; cloud_i < total_clouds; ++cloud_i) {
        ctx.fillStyle = color;

        ctx.save();
        ctx.translate(
            (cloud_i + 1) * center_radius + center_radius * cloud_i,
            center_radius * 2.3
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

const div = document.getElementById("bg1");
const div2 = document.getElementById("bg2");
const div3 = document.getElementById("bg3");

make_cloud(div,  "red");
make_cloud(div2, "blue");
make_cloud(div3, "green");