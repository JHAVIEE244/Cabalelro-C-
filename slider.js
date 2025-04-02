let slideIndex = 0; // Start with the first slide
let autoSlideTimeout; // Variable to store the auto-slide timeout
showSlides();

function plusSlides(n) {
    clearTimeout(autoSlideTimeout); // Reset auto-slide timer on manual navigation
    slideIndex += n;
    if (slideIndex < 0) { slideIndex = document.getElementsByClassName("slide").length - 1; }
    showSlides();
}

function currentSlide(n) {
    clearTimeout(autoSlideTimeout); // Reset auto-slide timer on manual navigation
    showSlides(slideIndex = n - 1);
}

function showSlides() {
    let i;
    let slides = document.getElementsByClassName("slide");
    let dots = document.getElementsByClassName("dot");
    for (i = 0; i < slides.length; i++) {
        slides[i].style.display = "none";
    }
    if (slideIndex >= slides.length) { slideIndex = 0; }
    for (i = 0; i < dots.length; i++) {
        dots[i].className = dots[i].className.replace(" active", "");
    }
    slides[slideIndex].style.display = "block";
    dots[slideIndex].className += " active";
    autoSlideTimeout = setTimeout(() => {
        slideIndex++;
        showSlides();
    }, 3000); 
}
