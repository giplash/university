import db from '../utils/db';

export default class CardModel {
  static async getCard(cardData) {
    const { number, ownerName, cvv2, validity } = cardData;
    const res = await db.execute(`
      SELECT * 
      FROM cards 
      WHERE number = ${number} AND ownerName = '${ownerName}' AND CVV2 = ${cvv2} AND validity = '${validity}'
    `);
    return res[0][0];
  }

  static async getBalance(cardData) {
    const card = await CardModel.getCard(cardData);
    if (!card) {
      throw new Error('Incorrect card data');
    } else {
      return card.balance;
    }
  }

  static async reduceBalance(cardData, price) {
    const card = await CardModel.getCard(cardData);
    const { number, ownerName, cvv2, validity } = cardData;
    return await db.execute(`
      UPDATE cards 
      SET balance = ${card.balance - price} 
      WHERE number = ${number} AND ownerName = '${ownerName}' AND CVV2 = ${cvv2} AND validity = '${validity}'
    `);
  }
}