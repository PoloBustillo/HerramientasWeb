const clickTag = (e) => {
  console.log("InitTag");
  let tags = document.getElementsByClassName("badge");
  let articleNames = document.getElementsByTagName("h3");
  articlesArray = Array.from(articleNames);
  articlesArray.map((article) => {
    console.log(article.getElementsByTagName("b").innerHTML);
  });

  for (let i = 0; i < tags.length; i++) {
    tags[i].addEventListener("click", (e) => {
      e.target.classList.add("tag");
      for (let i = 0; i < tags.length; i++) {
        if (tags[i] !== e.target) {
          tags[i].classList.remove("tag");
        }
      }
    });
  }
};
clickTag();
