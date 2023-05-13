function resize_gameboy() {
  const gb = document.querySelector(".gameboy-container");
  const parent = gb.parentElement;
  if (parent.clientWidth > gb.clientWidth) {
    return;
  }

  const scale = parent.clientWidth / gb.clientWidth * 0.9;
  const translateX = -((parent.clientWidth - gb.clientWidth) / 4) * scale;
  const translateY = 0; (parent.clientHeight - gb.clientHeight) / 2;

  gb.style.transform = `translate(${translateX}px, ${translateY}px) scale(${scale})`;
}


window.addEventListener('load', function () {
  resize_gameboy();
  _make_all_clouds();
});

window.addEventListener('resize', function () {
  resize_gameboy();
  _make_all_clouds();
});