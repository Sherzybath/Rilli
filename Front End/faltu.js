// Save the current state when a change happens
function displayDay() {
  var daysOfWeek = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];
  var currentTime = new Date();
  var currentDay = daysOfWeek[currentTime.getDay()];

  document.getElementById("current-day").textContent = currentDay;
}
function displayDate() {
  var currentDate = new Date();
  var year = currentDate.getFullYear();
  var month = currentDate.getMonth() + 1; // Adding 1 since months are zero-indexed
  var day = currentDate.getDate();

  // Add leading zeros if necessary
  if (month < 10) {
    month = "0" + month;
  }
  if (day < 10) {
    day = "0" + day;
  }

  var formattedDate = day;
  document.getElementById("current-date").textContent = formattedDate;

  // Update date every day
  setTimeout(displayDate, 86400000); // 24 hours in milliseconds
}
let currentExpandable = null;

function toggleExpand(element) {
  if (currentExpandable !== null) {
    currentExpandable.classList.remove("expanded");
  }
  element.classList.add("expanded");
  currentExpandable = element;
}

function createExpandableDiv() {
  const container = document.getElementById("expandable-container");
  const newDiv = document.createElement("div");
  newDiv.className = "expandable";
  newDiv.onclick = function () {
    toggleExpand(this);
  };
  newDiv.innerHTML = `
    <input
        type="text"
        class="editableInput"
        value="Task"
        oninput="updateInputValue(this)"
    />
    <input
        type="text"
        class="editableInput2"
        value="Things to do"
        oninput="updateInputValue()"
    />

`;
  container.appendChild(newDiv);
}

function removeLastExpandableDiv() {
  const container = document.getElementById("expandable-container");
  const expandableDivs = container.getElementsByClassName("expandable");
  if (expandableDivs.length > 0) {
    const lastDiv = expandableDivs[expandableDivs.length - 1];
    container.removeChild(lastDiv);
    if (lastDiv === currentExpandable) {
      currentExpandable = null;
    }
  }
}

function updateInputValue(inputElement) {
  // Get the parent expandable div
  const parentDiv = inputElement.closest(".expandable");
  if (parentDiv) {
    const value = inputElement.value;
    // Update the input value within the parent expandable div
    const editableInput = parentDiv.querySelector(".editableInput");
    if (editableInput) {
      editableInput.value = value;
    }
  }
}
// asdasdASODIOSAIDJOSAIDJOISAJDOISAJDOISAJDOISAJDOISAJODSAJODISAJODIJSAOIDJSAODIJ
// function updateWeekNumbers() {
//   const currentDate = new Date();
//   const labels = document.querySelectorAll(
//     ".sun, .mon, .tue, .wed, .thu, .fri, .sat"
//   );

//   // Calculate the start of the current week (Sunday)
//   const startDate = new Date(currentDate);
//   startDate.setDate(currentDate.getDate() - currentDate.getDay());

//   // Loop through the labels and update their text content with day numbers
//   labels.forEach((label, index) => {
//     const date = new Date(startDate);
//     date.setDate(startDate.getDate() + index);
//     const dayNumber = date.getDate();

//     // Wrap around for days below 1 (previous month) or above 31 (next month)
//     label.textContent =
//       dayNumber <= 0
//         ? 31 + dayNumber
//         : dayNumber > 31
//         ? dayNumber - 31
//         : dayNumber;
//   });
// }

// // Function to show the next week's day numbers
// function showNextWeek() {
//   const labels = document.querySelectorAll(
//     ".sun, .mon, .tue, .wed, .thu, .fri, .sat"
//   );

//   labels.forEach((label) => {
//     const currentNumber = parseInt(label.textContent);
//     label.textContent =
//       currentNumber + 7 > 31 ? currentNumber + 7 - 31 : currentNumber + 7;
//   });
// }

// // Function to show the previous week's day numbers
// function showPreviousWeek() {
//   const labels = document.querySelectorAll(
//     ".sun, .mon, .tue, .wed, .thu, .fri, .sat"
//   );

//   labels.forEach((label) => {
//     const currentNumber = parseInt(label.textContent);
//     label.textContent =
//       currentNumber - 7 < 1 ? currentNumber - 7 + 31 : currentNumber - 7;
//   });
// }

// // Add event listeners to the Next and Previous Week buttons
// document.getElementById("nextWeek").addEventListener("click", showNextWeek);
// document.getElementById("prevWeek").addEventListener("click", showPreviousWeek);

// Initial call to display the current week's day numbers
