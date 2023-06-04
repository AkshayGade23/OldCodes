//Selectors
const totalNumber = document.querySelector("#total-number");
const deathNumber = document.querySelector("#death-number");
const recoveredNumber = document.querySelector("#recovered-number");
const countryInput = document.querySelector(".input-text");
const readyToGo = document.querySelector(".ready-to-go");

//Event Listeners
readyToGo.addEventListener("click", startComputing);

//Functions

function updateStats(corona) {
  // console.log(corona);
  let total = corona.cases;
  let death = corona.deaths;
  let recover = corona.recovered;
  totalNumber.innerText = total;
  deathNumber.innerText = death;
  recoveredNumber.innerText = recover;
}

function startComputing() {
  let countryName = countryInput.value;
  if (!countryName) return;

  let apiEndPoint = `https://coronavirus-19-api.herokuapp.com/countries/${countryName}`;

  //Requesting Api
  fetch(apiEndPoint)
    .then((response) => response.json())
    .then((jsonData) => {
      updateStats(jsonData);
    })
    .catch((err) => alert("Country Not Found"));
}

countryInput.addEventListener("focus", () => {
  countryInput.value = "";
});

readyToGo.click();
