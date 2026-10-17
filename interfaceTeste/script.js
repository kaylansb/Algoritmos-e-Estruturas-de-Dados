function soma() {
  const a = parseInt(document.getElementById("a").value);
  const b = parseInt(document.getElementById("b").value);
  document.getElementById("resultado").textContent = Module._soma(a, b);
}
