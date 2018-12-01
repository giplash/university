import db from '../utils/db';

export default class {
  static async fetchAll() {
    const res = await db.execute(`
      SELECT * 
      FROM bills 
    `);
    return res[0];
  }

  static async add(info) {
    const { name, price, date, quantity } = info;
    return await db.execute(`
      INSERT INTO bills (name, price, date, quantity)
      VALUES ('${name}', ${price}, '${date}', ${quantity})
    `);

  }
}