function displayToggle(x){
    sty = document.getElementById(x).style.display;
    // console.log(sty);
    if(sty === 'none'){
        document.getElementById(x).style.display = "block";
    }
    else{
        document.getElementById(x).style.display = "none";
    }
}


function rpsDisplayTggle(rock,paper,scissors,v){
    //console.log(rock,paper,scissors)

    winner = playRPS(v);
    prefix = 'the'

    if (winner === 'draw'){
        prefix = 'it is a'
    }


    if (v === 'rock'){
        displayToggle(rock);
        document.getElementById(paper).style.display = "none";
        document.getElementById(scissors).style.display = "none";
    } else if ( v === 'paper'){
        displayToggle(paper);
        document.getElementById(rock).style.display = "none";
        document.getElementById(scissors).style.display = "none";
    } else if ( v === 'scissors'){
        displayToggle(scissors);
        document.getElementById(rock).style.display = "none";
        document.getElementById(paper).style.display = "none";
    } else{
        console.log('hmm?');
        document.getElementById(rock).style.display = "none";
        document.getElementById(paper).style.display = "none";
        document.getElementById(scissors).style.display = "none";
    }
    document.getElementById('Game').innerHTML = `we played rock paper scissors, and ${prefix} ${winner}!`
}



// vvv I wrote this for practice about a month ago vvv

function getUserChoice (userInput){
    userInput = userInput.toLowerCase()
    
    if (userInput === 'rock' || userInput === 'paper' || userInput === 'scissors'){
    return userInput
    } else {
      console.log('Invalid choice');
    }
  
  }
  
  
  function getComputerChoice(){
    computerChoice = Math.floor(Math.random()*3);
  
    switch(computerChoice){
      case 0:
        return 'rock'
      break;
  
      case 1:
        return 'paper'
      break;
  
      case 2:
        return 'scissors'
      break;
    }
  
  }
  
  function determinWinner(p1, p2){
    if (p1 === p2){
      return 'draw';
      }
     
      if (p1 === 'rock'){
        if (p2 === 'paper'){
          return 'computer wins';
        }
        else if(p2 === 'scissors') {
          return 'player wins';
        }
      }
  
     if (p1 === 'paper'){
        if (p2 === 'scissors'){
          return 'computer wins';
        }
        else if(p2 === 'rock') {
          return 'player wins';
        }
      }
      
     if (p1 === 'scissors'){
        if (p2 === 'rock'){
          return 'computer wins';
        }
        else if(p2 === 'paper') {
          return 'player wins';
        }
      }
  
  }
  
  
  
  
  //console.log(determinWinner('rock',getComputerChoice()));
  //console.log(getUserChoice('roc'));
  //console.log(getComputerChoice());
  
  
  
  function playRPS(x){
    let userChoice = getUserChoice(x);
    let computerChoice = getComputerChoice()
    if (userChoice != 'bomb'&&userChoice != undefined){
        winner = determinWinner(userChoice,computerChoice);
        console.log(`You chose ${userChoice}, and the computer chose ${computerChoice}. ${determinWinner(userChoice, computerChoice)}!`)
    } else if(userChoice != undefined) {
        winner = "player?"
        console.log('You blew up the computer... You win?')
    } else {
        winner = "none"
        console.log('no winner!')
    }
    return winner
  }
  
