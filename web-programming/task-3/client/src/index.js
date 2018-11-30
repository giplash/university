import data from './data';
import * as utils from './utils';
import * as api from './api';
import './less/main.less';
import $ from 'jQuery';


const state = {
  data: null,
  isLoadingData: false,
  screen: 'main',
  sort: 'name',
  bills: [],
  tableMode: null,
  selectedItem: null,
  orderQuantity: null
};

const setState = obj => {
  Object.keys(obj).forEach(key => {
    state[key] = obj[key];
  });
  render();
};

const render = () => {
  $('#root').html('<div class="container" />');
  const { screen } = state;
  switch (screen) {
    case 'main':
      renderMainScreen();
      break;
    case 'table':
      renderButtons();
      renderTable();
      break;
    case 'add':
      renderAddScreen();
      break;
    case 'buy':
      renderBuyScreen();
      break;
    case 'card':
      renderCardScreen();
      break;
    case 'post-buy':
      renderPostBuyScreen();
      break;
    case 'bills':
      renderBillsScreen();
      break;
    }
};

const renderMainScreen = () => {
  $('.container').append(
    `<div class="main-buttons">
      <button class="main-buttons__button" data-table-mode="1">Table 1</button>
      <button class="main-buttons__button" data-table-mode="2">Table 2</button>
      <button class="main-buttons__button" data-table-mode="3">Table 3</button>
    </div>`
  );
  $('.main-buttons__button').click((e) => {
    setState({
      screen: 'table',
      tableMode: +$(e.target).attr('data-table-mode')
    });
  });
};

const renderButtons = () => {
  const { selectedItem } = state;
  $('.container').append(`
    <div class="buttons">
      <button class="buttons__back">Back</button>
      <button class="buttons__buy" ${selectedItem === null ? 'disabled' : ''}>Buy</button>
      <button class="buttons__add">Add</button>
      <button class="buttons__bills">Bills</button>
    </div>
  `);
  $('.buttons__back').click(() => setState({
    screen: 'main',
    selectedItem: null
  }));
  $('.buttons__add').click(() => setState({
    screen: 'add',
  }));
  $('.buttons__buy').click(() => setState({
    screen: 'buy',
  }));
  $('.buttons__bills').click(() => setState({
    screen: 'bills',
  }));
};

const renderTable = async () => {
  const { data, isLoadingData, tableMode, selectedItem, sort } = state;
  if (data === null && isLoadingData === false) {
    setState({
      isLoadingData: true
    });
    api.fetchData().then(data => {
      setState({ data, isLoadingData: false });
    });
    return;
  }
  if (isLoadingData === true) {
    $('.container').append(
      '<p>Loading...</p>'
    );
    return;
  }
  $('.container').append(
    `<table><tbody>
      <tr>
        ${tableMode === 3 ? '<th class="main-row__id">Id</th>' : ''}
        <th class="main-row__name">Name</th>
        <th class="main-row__price">Price</th>
        ${tableMode !== 1 ? '<th class="main-row__quantity">Quantity</th>' : ''}
      </tr>
    </tbody></table>`
  );
  const sortedDataArray = utils.sort(data, sort);
  $('tbody').append(sortedDataArray.reduce((str, { id, name, price, quantity }) => {
    if (quantity === 0) return str;
    return str + `
      <tr class="${selectedItem === id ? 'item-row_selected' : 'item-row'}" data-id="${id}">
        ${tableMode === 3 ? `<td>${id}</td>` : ''}
        <td>${name}</td>
        <td>${price}</td>
        ${tableMode !== 1 ? `<td>${quantity}</td>` : ''}
      </tr>
    `;
  }, ''));
  $('.main-row__id').click(() => {
    setState({
      sort: 'id'
    });
  });
  $('.main-row__name').click(() => {
    setState({
      sort: 'name'
    });
  });
  $('.main-row__price').click(() => {
    setState({
      sort: 'price'
    });
  });
  $('.main-row__quantity').click(() => {
    setState({
      sort: 'quantity'
    });
  });
  $('.item-row').click(function() {
    setState({
      selectedItem: +$(this).attr('data-id')
    });
  });
};

const renderAddScreen = () => {
  const { tableMode, data } = state;
  $('.container').append(`
    <form class="add-form">
      <div class="add-form__row">
        <label for="add-form__name">Name</label>
        <input id="add-form__name" type="text" />
      </div>
      ${tableMode !== 1 ? `<div class="add-form__row">
        <label for="add-form__quantity">Quantity</label>
        <input id="add-form__quantity" type="text" />
      </div>` : '' }
      <div class="add-form__row">
        <label for="add-form__price">Price</label>
        <input id="add-form__price" type="text" />
      </div>
      <div class="add-form__row">
        <button class="add-form__submit" type="submit">Add</button>
        <button class="add-form__back" type="button">Back</button>
      </div>
    </form>
  `);
  $('.add-form').on('submit', e => {
    e.preventDefault();
    const name = $('#add-form__name').val();
    const price = +$('#add-form__price').val();
    const quantity = tableMode !== 1 ? +$('#add-form__quantity').val() : utils.generateQuantity();
    const id = utils.generateId(data);
    const messages = utils.validate(name, price, quantity);
    if (messages.some(item => item !== null)) {
      alert(messages
        .filter(item => item !== null)
        .join('\n')
      );
      return;
    }
    const prevState = JSON.parse(JSON.stringify(state));
    api.addProduct({ id, name, price, quantity }).catch(() => {
      setState({ ...prevState });
    });
    setState({
      data: { ...data, [id]: { id, name, price, quantity } },
      screen: 'table',
    });
  });
  $('.add-form__back').click(() => {
    setState({
      screen: 'table'
    });
  });
};

const renderBuyScreen = () => {
  const { selectedItem: id, data, orderQuantity } = state;
  const item = data[id];
  $('.container').append(`
    <form class="buy-form">
      <div class="buy-form__row">
        <label for="buy-form__name">Name</label>
        <input type="text" id="buy-form__name" value="${item.name}" readonly />
      </div>
      <div class="buy-form__row">
        <label for="buy-form__price">Price</label>
        <input 
            type="text" 
            disabled 
            id="buy-form__price" 
            value="${orderQuantity * item.price || item.price}" 
            readonly 
          />
      </div>
      <div class="buy-form__row">
        <label for="buy-form__quantity">Quantity</label>
        <input type="number" id="buy-form__quantity" value="${orderQuantity || 1}" min="1"/>
    
      </div>
      <div class="buy-form__row">
        <button id="buy-form__back">Back</button>
        <button id="buy-form__submit"type="submit">Buy</button>
      </div>
    </form>
  `);
  $('#buy-form__quantity').on('input', e => {
    const value = +e.target.value;
    const price = item.price;
    if (value > item.quantity) {
      e.target.value = item.quantity;
    } 
    $('#buy-form__price').val(price * e.target.value);
  });
  $('#buy-form__back').click(() => {
    setState({
      screen: 'table'
    });
  });
  $('.buy-form').submit(() => {
    setState({
      data: {
        ...data, 
        [id]: { 
          ...data[id], 
          quantity: data[id].quantity - +$('#buy-form__quantity').val()
        }
      },
      orderQuantity: +$('#buy-form__quantity').val(),
      screen: 'card'
    });
  });
};

const renderCardScreen = () => {
  $('.container').append(`
    <form class="card-form">
        <div class="card-form__row">
            <label for="card-number">Card number:</label>
            <input type="text" id="card-number" class="card-form__input">                
        </div>
        <div class="card-form__row">
            <label for="card-owner">Card owner name:</label>
            <input type="text" id="card-owner" class="card-form__input">                
        </div>
        <div class="card-form__row">
            <label for="card-cvv2">CVV2:</label>
            <input type="text" id="card-cvv2" class="card-form__input">                
        </div>
        <div class="card-form__row">
            <label for="card-validity">Validity: (MM/YY)</label>
            <input type="text" id="card-validity" class="card-form__input">                
        </div>
        <div class="card-form__row">
            <button type="submit">Submit</button> 
            <button class="card-validity__back-button">Back</button>               
        </div>
    </form>
  `);
  const { selectedItem, orderQuantity } = state;
  $('.card-form').on('submit', (e) => {
    e.preventDefault();
    const number = +$('#card-number').val();
    const name = $('#card-owner').val();
    const cvv2 = +$('#card-cvv2').val();
    const validity =  $('#card-validity').val();
    const messages = utils.validateCard({ number, name, cvv2, validity });
    if (messages.some(item => item !== null)) {
      alert(messages
        .filter(item => item !== null)
        .join('\n')
      );
      return;
    }
    api.buyProduct(
      selectedItem, orderQuantity, {
        ownerName: name,
        number,
        cvv2,
        validity
      })
      .then(() => {
        setState({
          screen: 'post-buy'
        });
      });
  });
  $('.card-validity__back-button').click(() => {
    setState({
      screen: 'buy'
    })
  })
};

const renderPostBuyScreen = () => {
  const { selectedItem: id, data, bills, orderQuantity } = state;
  const item = data[id];
  $('.container').append(`
    <form "post-buy-form">
      <div class="post-buy-form__row">
        <p class="post-buy-form__text">Save bill?</p>
      </div>
      <div class="post-buy-form__row">
        <button class="post-buy-form__button post-buy-form__button_yes">Yes</button>
        <button class="post-buy-form__button post-buy-form__button_no">No</button>
      </div>
    </form>
  `);
  $('.post-buy-form__button_no').click((e) => {
    e.preventDefault();
    setState({
      screen: 'table',
      selectedItem: null,
      orderQuantity: null
    });
  });
  $('.post-buy-form__button_yes').click((e) => {
    e.preventDefault();
    setState({
      screen: 'table',
      selectedItem: null,
      orderQuantity: null,
      bills: [
        ...bills,
        {
          name: item.name,
          price: orderQuantity * item.price,
          date: new Date(),
          quantity: orderQuantity
        }
      ]
    });
  });
};

const renderBillsScreen = () => {
  const { bills } = state;
  $('.container').append(`
    <div class="bills">
      <div class="bills__buttons">
        <button class="bills__back-button">Back</button>
      </div>
    </div>
  `);
  $('.bills__back-button').click(() => {
    setState({
      screen: 'table'
    });
  });
  if (bills.length === 0) {
    $('.container').append(`
      <p>Seems you have no bills yet</p>
    `);
  }
  bills.forEach(({ date, name, price, quantity }) => {
    $('.bills').append(`
      <div class="bills__item">
        <div class="bills__item-row">
          <span class="bills__item-key">Name: </span>
          <span class="bills__item-value">${name}</span>
        </div>
        <div class="bills__item-row">
          <span class="bills__item-key">Date: </span>
          <span class="bills__item-value">${date}</span>
        </div>
        <div class="bills__item-row">
          <span class="bills__item-key">Price: </span>
          <span class="bills__item-value">${price}</span>
        </div>
        <div class="bills__item-row">
          <span class="bills__item-key">Quantity: </span>
          <span class="bills__item-value">${quantity}</span>
        </div>
      </div>
    `);
  });
};


render();
