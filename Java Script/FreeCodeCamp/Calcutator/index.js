let num1 = 10
let num2 = 12
document.getElementById("num1-el").textContent = num1
document.getElementById("num2-el").textContent = num2

let sumEl = document.getElementById("sum-el")

function Add(){
    let result = num1 + num2
    sumEl.textContent = "Ans -> " + result
}
function Subtract(){
    let result = num1 - num2
    sumEl.textContent = "Ans -> " + result
}
function Multiply(){
    let result = num1 * num2
    sumEl.textContent = "Ans -> " + result
}
function Divide(){
    let result = num1 / num2
    sumEl.textContent = "Ans -> " + result
}