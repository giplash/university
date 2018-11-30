import db from '../utils/db'

export default class {
  static async fetchAll() {
    try {
      const res = await db.execute('SELECT * FROM products');
      return res[0];
    } catch (e) {
      console.log(e);
    }
  }
}