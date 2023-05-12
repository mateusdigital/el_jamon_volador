function resize_gameboy() {
  const gb = document.querySelector(".gameboy-container");
  const parent = gb.parentElement;
  if (parent.clientWidth > gb.clientWidth) {
    return;
  }

  const scale = parent.clientWidth / gb.clientWidth;
  const parent_height = gb.clientHeight * scale;

  gb.style.transform = `scale(${scale})`;
  parent.style.height = `${parent_height}px`;
}


window.addEventListener('load', function () {
  resize_gameboy();
  _make_all_clouds();
});

window.addEventListener('resize', function () {
  resize_gameboy();
  _make_all_clouds();
});