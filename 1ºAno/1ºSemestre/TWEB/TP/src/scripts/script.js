// slideshow
var slideIndex = 0;
function slideshow() {
  let i;
  let x = document.getElementsByClassName("slideImage");
  for (i = 0; i < x.length; i++) {
    x[i].style.display = "none";
  }
  slideIndex++;
  if (slideIndex > x.length) { slideIndex = 1 }
  x[slideIndex - 1].style.display = "block";
  setTimeout(slideshow, 2000);
}
// fim do slideshow


// collapse
function dropdown() {
  let coll = document.getElementsByClassName("collapse");
  let index;
  for (index = 0; index < coll.length; index++) {
    coll[index].addEventListener("click", function () {
      this.classList.toggle("active");
      var content = this.nextElementSibling;
      if (content.style.maxHeight) {
        content.style.maxHeight = null;
      } else {
        content.style.maxHeight = content.scrollHeight + "px";
      }
    });
  }
}
// fim do collapse

//Login
function validar(form){
  let username = document.getElementById("username").value;
  let password = document.getElementById("password").value;
  if ( form.username.value == "test" && form.password.value == "test"){
    alert ("Login com sucesso");
    window.location = "sucesso.html";
  }
  else{
    alert("Username ou password errados");
    }
  }
//fim do login

//registar
function registo(form){
  let username = document.getElementById("username").value;
  let password = document.getElementById("password").value;
  if(form.username.value && form.password.value){
    alert("Registado");
    window.location = "registadosucesso.html";
  }
  else{
    alert("Preencha os dados corretamente");
  }
}
//fim do registar
