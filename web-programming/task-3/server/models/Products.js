import db from '../utils/db'

export default class {
  static async fetchAll() {
    const res = await db.execute('SELECT * FROM products');
    return res[0];
  }

  static async getName(id) {
    const res = await db.execute(`
      SELECT *
      FROM products
      WHERE id = ${id}
    `);
    return res[0][0].name;
  }

  static async reduceQuantity(id, diff) {
    const res = await db.execute(`
      SELECT * 
      FROM products 
      WHERE id = ${id}
    `);
    const quantity = res[0][0].quantity;
    return await db.execute(`
      UPDATE products 
      SET quantity = ${quantity - diff} 
      WHERE id = ${id}
    `);
  }

  static async setQuantity(id, newQuantity) {
    return await db.execute(`
      UPDATE products 
      SET quantity = ${newQuantity} 
      WHERE id = ${id}
    `);
  }

  static async getPrice(id, quantity) {
    const res = await db.execute(`  
      SELECT * 
      FROM products 
      WHERE id = ${id}
    `);
    const item = res[0][0];
    if (!item) {
      throw new Error('Incorrect product ID');
    } else {
      return item.price * quantity;
    }
  }

  static async addProduct(info) {
    const { id, name, price, quantity } = info;
    return await db.execute(`
      INSERT INTO products (id, name, price, quantity)
      VALUES (${id}, '${name}', ${price}, ${quantity})
    `);
  }

}