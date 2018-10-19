import data from './data';
import '../less/main.less';
import $ from 'jQuery';
const $root = $('#root');

const state = {
  data,
  screen: 'main',
  sort: 'name',
  tableMode: null,
  selectedItem: null
};

const setState = obj => {
  const Date1 = Date.now();
  Object.keys(obj).forEach(key => {
    state[key] = obj[key];
  });
  console.log(state);
  render();
  const Date2 = Date.now();
  console.log(Date2 - Date1);
};

const render = () => {
  $root.html('<div class="container" />');
  const { screen } = state;
  switch (screen) {
  case 'main':
    renderMainScreen();
    break;
  case 'table':
    renderButtons();
    renderTable();
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
    </div>
  `);
  $('.buttons__back').click(() => setState({
    screen: 'main',
    selectedItem: null
  }));
};

const renderTable = () => {
  const { data, tableMode, selectedItem } = state;
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
  $('tbody').append(Object.values(data).reduce((str, { id, name, price, quantity }) => {
    return str + `
      <tr class="${selectedItem === id ? 'item-row_selected' : 'item-row'}" data-id="${id}">
        ${tableMode === 3 ? `<td>${id}</td>` : ''}
        <td>${name}</td>
        <td>${price}</td>
        ${tableMode !== 1 ? `<td>${quantity}</td>` : ''}
      </tr>
    `;
  }, ''));
  $('.item-row').click(function() {
    setState({
      selectedItem: +$(this).attr('data-id')
    });
  });
};
render();
