const precos = [60.90, 79.90, 20.00, 49.99, 25.50, 52.80];
const anos   = [1965, 1818, 1897, -700, 400, 650];

function mostrarInfo(textos) {
    originais.forEach((div, i) => {
        let info = div.querySelector(".info");
        if (!info) {
            info = document.createElement("div");
            info.className = "info";
            div.appendChild(info);
        }
        info.textContent = textos ? textos[i] : "";
    });
}

const lista = document.getElementById("listaResultado");
const originais = Array.from(lista.children); // índices 0 a 5, na ordem do C

function ordenar(funcaoC, textos) {
    const ponteiro = Module._malloc(6 * 4);
    funcaoC(ponteiro);
    const inicio = ponteiro / 4;
    const ordem = Array.from(Module.HEAP32.slice(inicio, inicio + 6));
    Module._free(ponteiro);

    ordem.forEach(i => lista.appendChild(originais[i]));
    mostrarInfo(textos);
}

Module.onRuntimeInitialized = () => {
    document.getElementById("botaoPreco").onclick = () =>
        ordenar(Module._ordenarPreco, precos.map(p => "R$ " + p.toFixed(2).replace(".", ",")));

    document.getElementById("botaoAlfa").onclick = () =>
        ordenar(Module._ordenarAlfabeto);   // sem textos: limpa a informação

    document.getElementById("botaoData").onclick = () =>
    ordenar(Module._ordenarLancamento, anos.map(a => a < 0 ? (-a) + " a.C." : a < 1000 ? a + " d.C." : String(a)));
};
