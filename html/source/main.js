//~---------------------------------------------------------------------------//
//                               *       +                                    //
//                         '                  |                               //
//                     ()    .-.,="``"=.    - o -                             //
//                           '=/_       \     |                               //
//                        *   |  '=._    |                                    //
//                             \     `=./`,        '                          //
//                          .   '=.__.=' `='      *                           //
//                 +                         +                                //
//                      O      *        '       .                             //
//                                                                            //
//  File      : main.js                                                       //
//  Project   : flappy_gb                                                     //
//  Date      : Apr 11, 2023                                                  //
//  License   : GPLv3                                                         //
//  Author    : mateus.digital <hello@mateus.digital>                         //
//  Copyright : mateus.digital - 2023                                         //
//                                                                            //
//  Description :                                                             //
//    Responsible to resize the game boy and make it responsive               //
//    Responsible to create the clouds.                                       //
//                                                                            //
//---------------------------------------------------------------------------~//

//
// Event Listeners
//

//------------------------------------------------------------------------------
window.addEventListener('load', function () {
  resize_gameboy();
  make_clouds   ();
});

window.addEventListener('resize', function () {
  resize_gameboy();
  make_clouds   ();
});



//
// Gameboy
//

//------------------------------------------------------------------------------
function resize_gameboy() {
  const gb = document.querySelector(".gameboy-container");
  const parent = gb.parentElement;
  if (parent.clientWidth > gb.clientWidth) {
    return;
  }

  const scale      = parent.clientWidth / gb.clientWidth * 0.9;
  const translateX = -((parent.clientWidth - gb.clientWidth) / 4) * scale;
  const translateY = 0;

  gb.style.transform = `translate(${translateX}px, ${translateY}px) scale(${scale})`;
}



//
// Clouds
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
  const ctx = canvas.getContext("2d");

  // Space that we can draw.
  const div_width = div.clientWidth;
  const div_height = div.clientHeight;

  canvas.width = div_width;
  canvas.height = div_height;

  const center_radius = 55 + (Math.random() * 10);
  const total_clouds = Math.trunc(div_width / center_radius) + 1; // Draw many clouds as need to fill the screen.
  const total_subclouds = 5 + (Math.random() * 4);

  for (let cloud_i = 0; cloud_i < total_clouds; ++cloud_i) {
    ctx.fillStyle = color;

    ctx.save();
    ctx.translate(
      (cloud_i + 1) * center_radius + (center_radius * cloud_i),
      center_radius * 1.8
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
function make_clouds() {
  let background_colors = [

    "#b7e7fa",
    "#c9efff",
    "#daf2fc",
    "#e5f6fd",
    "#fafdfe",
    "#f7f9f7",
  ]

  // DEBUG COLORS

  // if (false) {
  //   background_colors = [
  //     "red", "green", "blue", "yellow", "magenta", "cyan"
  //   ]
  // }


  const gb       = document.querySelector(".gameboy-container");
  const gb_aabb = gb.getBoundingClientRect();

  const background_divs = document.querySelectorAll(".cloud");

  const strict_height  = (gb_aabb.height / background_divs.length);
  const applied_buffer = 200;
  const applied_height = (strict_height + applied_buffer);

  const parent_height           = (strict_height * background_divs.length) + applied_buffer * 0.5;
  gb.parentElement.style.height = `${parent_height}px`;

  for (let i = 0; i < background_divs.length; ++i) {
    const element = background_divs[i];
    const color = background_colors[i];

    const pos = (strict_height * i);

    element.style.top = `${pos}px`;
    element.style.height = `${applied_height}px`;
    // element.style.backgroundColor = color;

    _make_cloud(element, color);

    // Controls the animation in CSS.
    const duration = Math.floor(Math.random() * 10) + 10;
    const delay = Math.floor(Math.random() * 3) + 1;

    element.style.setProperty("--delay", `${delay}s`);
    element.style.setProperty("--duration", `${duration}s`);
  }
}