const state = {
  data,
  pageId: 3,
  display: 'buttons',
  sort: 'name'
}

const formData = {
  nameInput: '',
  priceInput: '',
  quantityInput: ''
}

function setState(path, value) {
  if (path instanceof Array) {
    let currentPlace = data;
    for (let i = 0; i < path.length - 2; i++) {
      currentPlace = currentPlace[path[i]];
    }
    const lastItem = path[path.length - 1];
    currentPlace[lastItem] = value;
  } else {
    state[path] = value;
  }
  render();
}

function addDataItem(e) {
  e.preventDefault();
  const { data, pageId } = state;
  const { priceInput, nameInput, quantityInput } = formData;
  if ((priceInput === '' || isNaN(+priceInput)) || nameInput === '') {
    alert("Invalid data");
    return;
  }
  if ((quantityInput === '' || isNaN(+quantityInput)) && pageId !== 1) {
    alert("Invalid data");
    return;
  }
  let id = 1;
  while (data[id]) {
    id++;
  }
  const item = {
    id,
    name: nameInput,
    price: priceInput,
    quantity: quantityInput
  }
  setState('data', { 
    ...data,
    [id]: { ...item, quantity: quantityInput ? quantityInput : generateQuantity() }
  });
  for (let key in formData) {
    formData[key] = '';
  }
  document.querySelectorAll('form input').forEach(item => {
    item.value = '';
  })
}

function generateQuantity() {
  return Math.round(Math.random() * 30);
}

function render() {
  const { data, display, currentPage, pageId } = state;
  document.querySelector("#root").innerHTML = '';
  if (display === 'table') {
    renderBackButton();
    renderTable();
    renderForm();
  } else {
    renderButtons();
  }
  addListeners();
}


function renderButtons() {
  document.querySelector('#root').innerHTML += `
    <div class="buttons">
      <button id="button-1">Go to page 1</button>
      <button id="button-2">Go to page 2</button>
      <button id="button-3">Go to page 3</button>
    </div>`
  document.querySelectorAll('.buttons button').forEach(
    (item, i) => {
      item.addEventListener('click', function() {
        setState('pageId', +this.id.match(/\d/)[0]);
        setState('display', 'table');
      })
    }
  );
}

function renderBackButton() {
  document.querySelector('#root').innerHTML += `
    <div class="buttons">
      <button id="back-button">Go to main page</button>
    </div>`
  setTimeout(() => {
    document.getElementById('back-button').addEventListener(
      'click',
      function() {
        setState('display', 'buttons');
      }
    );
  }, 0);
}

function renderTable() {
  const { data, pageId } = state;
  document.querySelector('#root').innerHTML += `
    <div class="table">
      <div class="column" id="id">
      </div>
      <div class="column" id="name">
      </div>
      <div class="column" id="price">
      </div>
      <div class="column" id="quantity">
      </div>
    </div>`
  const nameMain = `<div class="cell main-cell">name</div>`
  document.querySelector("#name").innerHTML += nameMain;
  const priceMain = `<div class="cell main-cell">price</div>`
  document.querySelector("#price").innerHTML += priceMain;
  if (pageId === 2 || pageId === 3) {
    const quantityMain = `<div class="cell main-cell">quantity</div>`
    document.querySelector("#quantity").innerHTML += quantityMain;
  }
  if (pageId === 3) {
    const idMain = `<div class="cell main-cell">ID</div>`
    document.querySelector("#id").innerHTML += idMain;
  }
  sort(Object.values(data)).forEach((item) => {
    const name = `<div class="cell">${item.name}</div>`
    document.querySelector('#name').innerHTML += name;
    const price = `<div class="cell">${item.price}</div>`
    document.querySelector('#price').innerHTML += price;
    if (pageId === 2 || pageId === 3) {
      const quantity = `<div class="cell">${item.quantity}</div>`
      document.querySelector('#quantity').innerHTML += quantity;
    }
    if (pageId === 3) {
      const id = `<div class="cell">${item.id}</div>`
      document.querySelector('#id').innerHTML += id;
    }
  })
}

function renderForm() {
  const { pageId } = state;
  const { nameInput, priceInput, quantityInput } = formData;
  document.querySelector('#root').innerHTML += `
  <form>
    <label>
      Name
      <input type="text" id="name-input" value="${nameInput}"/>
    </label>
    <label>
      Price
      <input type="text" id="price-input" value="${priceInput}"/>
    </label>

    ${pageId >= 2 ? 
    `<label>
      Quantity
      <input type="text" id="quantity-input"  value="${quantityInput}"/>
    </label>` : ''
    }
    <button id="add-button">Add</button>
  </form> `
  document.querySelector('#name-input').addEventListener(
    'input',
    function(e) {
      formData.nameInput = e.target.value;
    }
  );
  document.querySelector('#price-input').addEventListener(
    'input',
    function(e) {
      formData.priceInput = e.target.value;
    }
  );
  if (document.querySelector('#quantity-input')) {
    document.querySelector('#quantity-input').addEventListener(
      'input',
      function(e) {
        formData.quantityInput = e.target.value;
      }
    );
  }
  document.querySelector('#add-button').addEventListener(
    'click',
    addDataItem
  )
}

function addListeners() {
  document.querySelectorAll('.main-cell').forEach(item => {
    item.addEventListener('click', function() {
      const parent = this.parentElement;
      setState('sort', parent.id)
    })
  })
};

function sort(array) {
  const { sort } = state;
  if (sort === 'name') {
    return array.sort((a, b) => a.name.localeCompare(b.name));
  }
  if (sort === 'id') {
    return array.sort((a, b) => a.id - b.id);
  }
  if (sort === 'price') {
    return array.sort((a, b) => a.price - b.price);
  }
  if (sort === 'quantity') {
    return array.sort((a, b) => a.quantity - b.quantity);
  }
}

render();
