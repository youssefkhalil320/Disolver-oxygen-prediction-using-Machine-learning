let calculateBtn = document.getElementById("calculate-btn");
let result = document.getElementById("result");
let calculate = () => {
  let p = Number(document.getElementById("pH").value);
  let r = Number(document.getElementById("DOSAT").value);
  let t = Number(document.getElementById("temp").value);
  let tds = Number(document.getElementById("TDS").value);
  let amount = (5.165218500638419)+(-0.01445154*p)+(-3.42376732*0.539226)+(0.07387896*r)+(t*-0.15761718)+(tds*4.95695377);

  result.innerHTML = `
  <div>DO: <span>${amount.toFixed(2)}</span></div>`;
};
calculateBtn.addEventListener("click", calculate);
window.addEventListener("load", calculate);