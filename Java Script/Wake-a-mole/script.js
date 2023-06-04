const square = document.querySelectorAll(".square");
const mole = document.querySelectorAll(".mole");
const timeLeft = document.querySelector("#time-left");
let score = document.querySelector("#score");
let pauseButton = document.querySelector(".stop");
let noobButton = document.querySelector("#noob-btn");
let proButton = document.querySelector("#pro-btn");
let eliteButton = document.querySelector("#elite-btn");


let result = 0, timerId = 0, counter = 0;
let currentTime = timeLeft.textContent;
let isPaused = false;
let isNoob, isPro, isElite, hitPosition;


function randomSquare() {
  square.forEach((clasName) => {
    clasName.classList.remove("mole");
  });
  let randomPosition = square[Math.floor(Math.random() * 8)];
  randomPosition.classList.add("mole");

  //assign the id of the randomPosition to hitPosition for us to use it later;
  hitPosition = randomPosition.id;
}

square.forEach((box) => {
  box.addEventListener("mouseup", () => {
    if (!isPaused) {
      if (box.id === hitPosition) {
        result++;
        score.textContent = result;
      }
    }
  });
});

function moveMole() {
  clearInterval(timerId);
  clearInterval(counter);
  let timeDelay;
  if (isNoob) {
    timeDelay = 1000;
  } else if (isPro) {
    timeDelay = 800;
  } else {
    timeDelay = 600;
  }
  timerId = setInterval(randomSquare, timeDelay);
  counter = setInterval(countDown, 1000);
}

function switchDifficulty(difficulty) {
  alert(difficulty + '  choosen !');
  timeLeft.textContent = 60;
  score.textContent = 0;
  result = 0;
  currentTime = 60;
  if (difficulty == 'noob') {
    easyMode();
    moveMole();
  } else if (difficulty == 'pro') {
    mediumMode();
    moveMole();
  } else {
    hardMode();
    moveMole();
  }
}

function countDown() {
  currentTime--;
  timeLeft.textContent = currentTime;

  if (currentTime === 0) {
    clearInterval(timerId);
    clearInterval(counter);
    alert("GAME OVER | TIME UP" + "\nYour Score is " + result);
  }
}

function switchMode() {
  clearInterval(timerId);
  clearInterval(counter);
  isPaused = true;
  pauseButton.style.color = "grey";
  pauseButton.disabled = true;
  noobButton.style.color = "grey";
  noobButton.disabled = true;
  proButton.style.color = "grey";
  proButton.disabled = true;
  eliteButton.style.color = "grey";
  eliteButton.disabled = true;
  alert("Reload/Restart this page to play again");
}

function easyMode() {
  noobButton.style.color = "grey";
  noobButton.disabled = true;
  proButton.style.color = "white";
  proButton.disabled = false;
  eliteButton.style.color = "white";
  eliteButton.disabled = false;
  isNoob = true;
  isPro = false;
  isElite = false;
}

function mediumMode() {
  proButton.style.color = "grey";
  proButton.disabled = true;
  noobButton.style.color = "white";
  noobButton.disabled = false;
  eliteButton.style.color = "white";
  eliteButton.disabled = false;
  isNoob = false;
  isPro = true;
  isElite = false;
}

function hardMode() {
  eliteButton.style.color = "grey";
  eliteButton.disabled = true;
  proButton.style.color = "white";
  proButton.disabled = false;
  noobButton.style.color = "white";
  noobButton.disabled = false;
  isNoob = false;
  isPro = false;
  isElite = true;
  moveMole();
}